# Mario pyramid program

from cs50 import get_int

def main():

    build_pyramid = make_pyramid()
    print(build_pyramid)

def make_pyramid():

    height = pyramid_height()

    for i in range(height):
        for space in range(height - (i + 1)):
            print(" ", end = "")
        for j in range(i + 1):
           print("#", end = "")
        print()
        
main()

def pyramid_height():

    while True:
        try:
            number = get_int("Enter Pyramid Height: " )
            if number > 0 and number <= 8:
                return number
        except ValueError:
            print("Invalid input, try again.")

make_pyramid()
