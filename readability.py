para = input("Text: ")
length = len(para)
words = 1
letters = 0
sentences = 0
for i in para:
    if i == " ":
        words += 1
    if i == "!" or i == "?" or i == ".":
        sentences += 1
    if i.isalpha():
        letters += 1
index = float(0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8)
grade = round(index)
if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print("Grade %i" %grade)