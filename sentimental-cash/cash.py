# Cash program

from cs50 import get_float



def main():



    print(f"${coins}")


def get_dollars():

    while True:
        dollars = get_float("Input change owed: $")
        if dollars > 0:
            return dollars


def calculate_coins():

    cents = int(get_dollars() * 100)

    quarter_amount = cents // 25
    cents = cents % 25

    dime_amount = cents // 10
    cents = cents % 10

    nickel_amount = cents // 5
    cents = cents % 5

    penny_amount = cents // 1

    coins = quarter_amount() + dime_amount + nickel_amount + penny_amount

main()
