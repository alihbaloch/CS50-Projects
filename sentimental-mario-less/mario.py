# Mario pyramid program

def main():
    height = Pyramid_Height()
    for i in range(height):
        for space in range(height):
            space -= 1
            print(".", end = "")
        for j in range(i + 1):
           print("#", end = "")
        print(" ")

def Pyramid_Height():

    while True:
        try:
            number = int(input("Enter Pyramid Height: " ))
            if number > 0 and number <= 8:
                return number
        except ValueError:
            print("This is not a number, try again.")

main()

