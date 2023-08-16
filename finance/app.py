import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

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
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    symbol = request.form.get("symbol")
    shares = request.form.get("shares")

    if request.method == "POST":
        if not symbol:
            return apology("Please type a stock symbol, 403")

        elif not shares or shares < 1:
            return apology("Please type in the number of shares, 403")

        # Lookup stock price
        stock_price = lookup(symbol)

        # if stock not found, return apology
        if stock_price is None:
            return apology("Stock not found")

        # Cost of stocks (stock price * number of shares inputted)
        stock_costs = stock_price["price"] * shares

        user_id = session["user_id"]

        # Select users cash
        cash_value = db.execute("SELECT cash FROM users WHERE id = ?", user_id)

        # Extract users cash using indexing directly into the dict
        user_cash = cash_value[0]["cash"]

        # Return apology if the user does not have sufficient funds
        if user_cash < stock_costs:
            return apology("Insufficient funds")

        # Otherwise purchase stocks and update the "users" table in the db
        user_cash_updated = user_cash - stock_costs
        db.execute("UPDATE users SET cash = ? WHERE id = ?", user_cash_updated, user_id)




        # Update the "transactions" table to record user's buying history
        db.execute(INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES ?, ?, ?, ?, ?", user_id, stock_price, shares, price, date)





        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
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

        symbol = request.form.get("symbol")
        quote = lookup(symbol)

        if not quote:
            return apology("Enter a valid symbol", 400)
        return render_template("quoted.html", quote=quote)

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

         # Ensure username was submitted
        if not username:
            return apology("you must provide a username", 403)

        # Ensure username does not already exist/is taken
        usernames = db.execute("SELECT 1 FROM users WHERE username = ?", username)

        if len(usernames) > 0:
            return apology("username already exists")

        # Ensure password was submitted
        elif not password:
            return apology("you must enter a password", 403)

        # Ensure passwords match
        elif not confirmation:
            return apology("please confirm your password", 403)

        elif confirmation != password:
            return apology("passwords do not match")

         # Hash users password to store in the database
        p_hash = generate_password_hash(password)

        # Insert user into users database
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, p_hash)

        # redirect user to login
        return redirect("/")

    # If user reached route via GET
    else:
        return render_template("register.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
