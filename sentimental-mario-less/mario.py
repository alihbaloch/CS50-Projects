# Mario pyramid program



def Pyramid_Height():

while True:
    number = int(input("Enter Pyramid Height: " ))
    try:
        if number < 1 or number > 8:
            print("invalid height")
            break
    except ValueError:
        print("Not a number")

    for i in range(number):
        print("#")
        for j in range(number):
            print("!")

    break
