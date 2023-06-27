# readability program

from cs50 import get_string


main():

grade_level = 0.0588 * L - 0.296 * S - 15.8

text = get_string("Enter text: ")

    #if grade_level < 1:
    #    print("Before Grade 1")
    #elif grade_level >= 16:
    #    print("Grade 16+")
    #else:
     #   print(f"Grade, round{grade_level}")


def calculations():

    letter_count = 0
    word_count = 0
    sentence_count = 0
    letter_length = len(text)


    for letters in range(letter_length):
        if letters = letters.lower() or letters.upper():
            letter_count += 1

    for words in range(letter_length):
        if words = (" "):
            word_count += 1

    for sentences in range(letter_length):
        if sentences = (".") or ("!") or ("?"):
            sentence_count += 1

main()

