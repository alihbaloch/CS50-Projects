# Mario pyramid program

def main():
    height = Pyramid_Height()



def Pyramid_Height():

    while True:
        try:
            number = int(input("Enter Pyramid Height: " ))
            if number > 0 and number <= 8:
                return number
        except ValueError:
            print("Not a number")

main()

