# Cash program

from cs50 import get_float



def main():

    dollar_amount = get_dollars()
    print(dollar_amount)



def get_dollars():

    while True:
        dollars = get_float("Input number of dollars: ")
        if dollars > 0:
            return dollars

main()



def quarters():

    quarters = dollars / 25
    return quarters

main()


def dimes():

    dimes = dollars / 10
    return dimes

main()

def nickels():

    nickels = dollars / 5
    return nickels

main()


def pennies():

    pennies = dollars / 1
    return pennies

main()