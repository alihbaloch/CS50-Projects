# Mario pyramid program

def main():
def Pyramid_Height():

    while True:
        try:
            number = int(input("Enter Pyramid Height: " ))
            if number > 1 and number < 8:
                return number
        except ValueError:
            print("Not a number")

    main()

