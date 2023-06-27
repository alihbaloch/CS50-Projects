# readability program

from cs50 import get_string

# get input from user
text = get_string("Enter text: ")

# to count letters
letter_count = 0
# to count words. Set to 1 to account for the last word
word_count = 1
# to count sentences
sentence_count = 0

# iterate over each character of users input
for characters in text:
    # check for alphabets and increment letter_count (takes into account both lower and uppercase)
    if characters.isalpha():
        letter_count += 1
    # check for spaces and increment word_count
    elif characters == " ":
        word_count += 1
    # check for sentences and increment sentence_count
    elif characters == "." or characters == "!" or characters == "?":
        sentence_count += 1

# assign seperate variables to counters for simplification
L = (letter_count / word_count) * 100
S = (sentence_count / word_count) * 100

# input variables inside (Coleman-Liau index) formula and calculate
CLi = 0.0588 * L - 0.296 * S - 15.8

# print calculated grade levels according to the formula 
if CLi < 1:
    print("Before Grade 1")
elif CLi >= 16:
    print("Grade 16+")
else:
    print(f"Grade, {round(CLi)}")