# readability program

from cs50 import get_string


def main():

    text = get_string("Enter text: ")

    letter_count = 0
    word_count = 0
    sentence_count = 0
    letter_length = len(text)


    for letters in range(len(text)):
        if letters == text.lower() or text.upper():
            letter_count += 1

    for words in range(len(text)):
        if words == (" "):
            word_count += 1

    for sentences in range(len(text)):
        if sentences == (".") or ("!") or ("?"):
            sentence_count += 1

    L = float (letter_count / word_count) * 100
    S = float (sentence_count / word_count) * 100

    grade_level = 0.0588 * L - 0.296 * S - 15.8

    if grade_level < 1:
        print("Before Grade 1")
    elif grade_level >= 16:
        print("Grade 16+")
    else:
        print(f"Grade, round{grade_level}")


#def calculations():



main()

