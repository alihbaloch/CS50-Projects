# Mario pyramid program

from cs50 import get_int


def main():

    # store pyramid_height function in a variable to use in loops
    height = pyramid_height()

    for i in range(height):
        # right allign triangle with spaces
        for space in range(height - (i + 1)):
            print(" ", end="")
        # print rows of hashes
        for j in range(i + 1):
            print("#", end="")
        # print a new line
        print()


def pyramid_height():

    while True:
        # get pyramid height from user with try and return if input within specified range
        try:
            number = get_int("Enter Pyramid Height: ")
            if number > 0 and number <= 8:
                return number
        # if input not an integer reprompt user
        except ValueError:
            # will print error when using input/ without cs50 library
            print("Invalid input, try again.")


main()