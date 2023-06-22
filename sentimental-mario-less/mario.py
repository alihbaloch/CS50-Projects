# Mario pyramid program

while True:
    number = int(input("Enter Pyramid Height: " ))
    if number < 1 or number > 8:
            print("invalid height")
            break
    for i in range(8):
        print("#")
        for j in range(8):
            print("#")

    break
