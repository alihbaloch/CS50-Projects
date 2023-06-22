# Mario pyramid program

while True:
    number = int(input("Enter Pyramid Height: " ))
    if number < 1 or number > 8:
            print("invalid height")
            break
    for i in range(number):
        print("#")
        for j in range(number):
            print("!")

    break
