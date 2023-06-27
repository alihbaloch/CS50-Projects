# readability program

from cs50 import get_string

# get input from user
text = get_string("Enter text: ")

# set counters to zero
letter_count = 0
# is set to 1 to account for the last word
word_count = 1
sentence_count = 0

for characters in range(text):
    # check for alphabets in increment count/ takes into account both lower and uppercase
    if characters.isalpha():
        letter_count += 1
    # check for spaces and increment
    elif characters == " ":
          word_count += 1
    # check for sentences and increment
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



