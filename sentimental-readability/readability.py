# readability program

from cs50 import get_string




text = get_string("Enter text: ")

letter_count = 0
word_count = 1
sentence_count = 0
length = len(text)



for i in text:
    if i.isalpha(): #lower() in text or letter.upper() in text:
        letter_count += 1
    elif i == " ":
          word_count += 1
    elif i == "." or i == "!" or i == "?":
         sentence_count += 1


    #for word in text:
    #for sentence in text:


    #L = (letter_count / word_count) * 100
    #S = (sentence_count / word_count) * 100

    grade_level = 0.0588 * (letter_count/word_count * 100) - 0.296 * (sentence_count/ word_count *100) - 15.8

    if grade_level < 1:
        print("Before Grade 1")
    elif grade_level >= 16:
        print("Grade 16+")
    else:
        print("Grade ", round(grade_level))


#def calculations():



