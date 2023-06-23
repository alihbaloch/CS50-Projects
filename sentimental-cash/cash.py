# Cash program

from cs50 import get_float



def main():

    dollar_amount = get_dollars()



def get_dollars():

    while True:
        dollars = get_float("Input number of dollars: ")
        if dollars > 0:
            return dollars

main()
