# readability program

from cs50 import get_string




text = get_string("Enter text: ")

letter_count = 0
word_count = 1
sentence_count = 0


for characters in text:
    if characters.isalpha(): #lower() in text or letter.upper() in text:
        letter_count += 1
    elif characters == " ":
          word_count += 1
    elif characters == "." or characters == "!" or characters == "?":
         sentence_count += 1

L = (letter_count / word_count) * 100
S = (sentence_count / word_count) * 100

grade_level = 0.0588 * (L) - 0.296 * (S) - 15.8

if grade_level < 1:
    print("Before Grade 1")
elif grade_level >= 16:
    print("Grade 16+")
else:
    print(f"Grade, {round(grade_level)}")


#def calculations():



