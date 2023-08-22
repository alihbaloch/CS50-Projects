import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Error codes
HTTP_BAD_REQUEST = 400
HTTP_UNAUTHORIZED = 401


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # Get the user's ID from the session
    user_id = session["user_id"]

    # Query the database for the user's stock details
    stock_details = db.execute(
        "SELECT symbol, SUM(shares) AS shares, price FROM transactions WHERE user_id = ? GROUP BY symbol", user_id)

    # Query the database to fetch the user's available cash balance
    user_cash = db.execute(
        "SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

    # Initialize grand total with the user's current cash balance
    grand_total = user_cash

    # Calculate the combined value of all stocks owned by the user
    for stock in stock_details:
        grand_total += stock["shares"] * stock["price"]

    # Render the user's portfolio page, providing all their stock details, cash balance, and grand total
    return render_template("index.html", stock_details=stock_details, user_cash=user_cash, grand_total=grand_total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # Access form data
    symbol = request.form.get("symbol")
    shares = request.form.get("shares")

    if request.method == "POST":

        # Ensure a stock symbol is inputted by the user
        if not symbol:
            return apology("Please input a stock", HTTP_BAD_REQUEST)

        # Convert share values to int
        try:
            int_shares = int(shares)
            if int_shares < 1:
                return apology("Please input shares greater than 0", HTTP_BAD_REQUEST)
        except ValueError:
            return apology("Invalid input, please ensure you input a valid positive integer for shares", HTTP_BAD_REQUEST)

        # Lookup stock price
        stock_price = lookup(symbol)

        # if stock not found, return apology
        if stock_price is None:
            return apology("Stock not found", HTTP_BAD_REQUEST)

        # Cost of stocks (stock price * number of shares inputted)
        stock_costs = stock_price["price"] * int_shares

        # Get the user's ID from the session
        user_id = session["user_id"]

        # Query the database to fetch the user's available cash balance
        user_cash = db.execute(
            "SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

        # Return apology if the user does not have sufficient funds
        if user_cash < stock_costs:
            return apology("Insufficient funds", HTTP_BAD_REQUEST)

        # Otherwise purchase stocks and update the "users" table in the db
        user_cash_updated = user_cash - stock_costs
        db.execute(
            "UPDATE users SET cash = ? WHERE id = ?", user_cash_updated, user_id)

        # Get the current date and time
        date = datetime.datetime.now()

        # Update the "transactions" table to record user's buying history
        db.execute(
            "INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES(?, ?, ?, ?, ?)",
            user_id, stock_price["symbol"], int_shares, stock_price["price"], date)

        # Notify the user about the details of their stock purchases with a flash message
        flash(
            f"You bought {int_shares} share(s) of {stock_price['name']} at ${stock_price['price']:.2f} each. Total cost of shares is: ${stock_costs:.2f}")

        # Redirect user to home page
        return redirect("/")

    # If user reached route via GET
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    # Get the user's ID from the session
    user_id = session["user_id"]

    # Query the database to get all the user's transactions
    user_transactions = db.execute(
        "SELECT * FROM transactions WHERE user_id = ? GROUP BY date", user_id)

    # Render the user's transactions history page, displaying the history of all their stock transactions
    return render_template("history.html", transactions=user_transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Access form data
        username = request.form.get("username")
        password = request.form.get("password")

        # Ensure username was submitted
        if not username:
            return apology("must provide username", HTTP_UNAUTHORIZED)

        # Ensure password was submitted
        elif not password:
            return apology("must provide password", HTTP_UNAUTHORIZED)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", username)

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], password):
            return apology("invalid username and/or password", HTTP_UNAUTHORIZED)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        name = db.execute(
            "SELECT username FROM users WHERE username = ?", username)

        # Redirect user to home page
        return redirect("/")

    # If user reached route via GET
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":

        # Access form data
        symbol = request.form.get("symbol")
        quote = lookup(symbol)

        # Ensure a valid symbol is inputted by the user
        if not quote:
            return apology("Enter a valid symbol", HTTP_BAD_REQUEST)
        return render_template("quoted.html", quote=quote)

    # If user reached route via GET
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":

        # Access form data
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Ensure a username was submitted
        if not username:
            return apology("you must provide a username", HTTP_BAD_REQUEST)

        # Ensure username does not already exist/is taken
        usernames = db.execute(
            "SELECT 1 FROM users WHERE username = ?", username)

        # If the username is already taken, return apology message
        if len(usernames) > 0:
            return apology("username already exists", HTTP_BAD_REQUEST)

        # Ensure password was submitted and confirmed
        elif not password or not confirmation:
            return apology("please enter a password and then confirm it", HTTP_BAD_REQUEST)

        # Ensure both passwords match
        elif confirmation != password:
            return apology("passwords do not match", HTTP_BAD_REQUEST)

         # Hash users password to store in the database
        p_hash = generate_password_hash(password)

        # Insert user into users database
        db.execute(
            "INSERT INTO users (username, hash) VALUES (?, ?)", username, p_hash)

        # Redirect user to home page
        return redirect("/")

    # If user reached route via GET
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # Get the user's ID from the session
    user_id = session["user_id"]

    if request.method == "POST":

        # Access form data
        symbol = request.form.get("symbol")
        shares_input = request.form.get("shares")

        # Ensure the user selects a stock
        if not symbol:
            return apology("Please select a stock", HTTP_BAD_REQUEST)
        # Ensure the user inputs a number of shares
        elif not shares_input:
            return apology("Please input number of shares", HTTP_BAD_REQUEST)

        # Retrieve the total number of shares owned by the user
        user_shares = db.execute(
            "SELECT SUM(shares) AS shares_total FROM transactions WHERE user_id=? AND symbol =?", user_id, symbol)[0]["shares_total"]

        # Convert shares into an integer
        try:
            int_shares = int(shares_input)
            # Ensure the user inputs a non-negative number of shares
            if int_shares < 1:
                return apology("Please input a positive number of shares", HTTP_BAD_REQUEST)
            # Ensure the user has enough shares to sell, if not return apology message
            elif int_shares > user_shares:
                return apology("You do not have enough shares of this stock", HTTP_BAD_REQUEST)

        except ValueError:
            return apology("Invalid input, please ensure you input a valid positive integer", HTTP_BAD_REQUEST)

        # Retrieve the current price of the stock
        stock_price = lookup(symbol)

        # Calculate the total value of the shares being sold (stock price * number of shares inputted)
        total_sold = stock_price["price"] * int_shares

        # Query the database to fetch the user's available cash balance
        user_cash = db.execute(
            "SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

        # Calculate the user's updated cash balance after selling shares
        user_cash_updated = user_cash + total_sold

        # Update the user's cash balance in the database
        db.execute(
            "UPDATE users SET cash = ? WHERE id = ?", user_cash_updated, user_id)

        # Get the current date and time
        date = datetime.datetime.now()

        # Insert the sale transaction into the database
        db.execute(
            "INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?)",
            user_id, stock_price["symbol"], -int_shares, stock_price["price"], date)

        # Notify the user about the details of their stocks sold with a flash message
        flash(
            f"You sold {int_shares} share(s) of {stock_price['name']} at ${stock_price['price']:.2f} each. Total earnings from shares sold: ${total_sold:.2f}")

        # redirect user to homepage
        return redirect("/")

    # If user reached route via GET
    else:

        # Retrieve symbols of stocks held by the user
        symbols = db.execute(
            "SELECT symbol FROM transactions WHERE user_id = ? GROUP BY symbol", user_id)

        # Display the "sell.html" template
        return render_template("sell.html", symbols=symbols)


@app.route("/password", methods=["GET", "POST"])
@login_required
def password():

    # Get the user's ID from the session
    user_id = session["user_id"]

    if request.method == "POST":

        # Access form data
        password = request.form.get("password")
        new_password = request.form.get("new_password")
        confirm_password = request.form.get("confirm_password")

        # Ensure both old and new password was submitted
        if not password or not new_password:
            return apology("Please fill all required fields: Enter both old and new password", HTTP_BAD_REQUEST)
        # Ensure confirmation password was submitted
        elif not confirm_password:
            return apology("Please confirm your password", HTTP_BAD_REQUEST)

        # Ensure new password matches confirmation password
        if new_password != confirm_password:
            return apology("New passwords do not match/try again", HTTP_BAD_REQUEST)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE id = ?", user_id)

        # Ensure old password matches
        if not check_password_hash(rows[0]["hash"], password):
            return apology("old password incorrect/try again", HTTP_UNAUTHORIZED)

        # Generate a new hash for the new password
        hash = generate_password_hash(new_password)

        update_hash = db.execute(
            "UPDATE users SET hash = ? WHERE id = ?", hash, user_id)

        # Notify the user about successful password change with a flash message
        flash(
            f"Your password has been successfully changed")

        # redirect user to home page
        return redirect("/")

    # If user reached route via GET
    else:
        return render_template("password.html")
