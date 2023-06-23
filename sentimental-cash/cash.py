# Cash program

from cs50 import get_float


def main():

    # convert dollar amount to cents
    cents = int(get_dollars() * 100)

    # calculate quarters
    quarter_amount = cents // 25
    cents = cents % 25

    # calculate dimes
    dime_amount = cents // 10
    cents = cents % 10

    # calculate nickels
    nickel_amount = cents // 5
    cents = cents % 5

    # calculate pennies
    penny_amount = cents // 1

    #  calculate coins
    coins = quarter_amount + dime_amount + nickel_amount + penny_amount

    # print change owed
    print(f"change owed: ${coins}")


def get_dollars():

    while True:
        dollars = get_float("Input change owed: $")
        if dollars > 0:
            return dollars


main()
