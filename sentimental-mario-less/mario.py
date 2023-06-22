# Mario pyramid program

from cs50 import get_int

def main():

    height = pyramid_height()

    for i in range(height):
        for space in range(height - (i + 1)):
            print(" ", end = "")
        for j in range(i + 1):
           print("#", end = "")
        print()


def pyramid_height():

    while True:
        try:
            number = get_int("Enter Pyramid Height: " )
            if number > 0 and number <= 8:
                return number
        except ValueError:
            print("Invalid input, try again.")

main()