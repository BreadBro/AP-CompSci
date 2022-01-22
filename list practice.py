#Problem 1
from operator import add, concat


list1 = [15, 100, 154, 20, 253, 530, 203]
for i in range(0, len(list1)):
    if list1[i] == 20:
        list1[i] = 200

print(list1)

#Problem 2 is the same as problem question as problem one but with a different output so idk

#Problem 3
list3 = [5, 20, 15, 20, 25, 50, 20]
count = 0
for i in range(0, len(list3)):
    if list3[i] == 20:
        count += 1

for i in range(0, count):
    list3.remove(20)
print(list3)

#Problem 4
count = 0
list4 = ["Mike", "", "Emma", "Kelly", "", "Brad"]
for i in range(0, len(list4)):
    if list4[i] == "":
        count += 1

for i in range(0, count):
    list4.remove("")
print(list4)

#Problem 5
list5 = [10, 20, [300, [5000, 6000], 500], 30, 40]
def addListInList(list5):
    for i in list5:
        if isinstance(i, list):
            addListInList(i)
        elif i == 6000:
            list5.append(7000)
    return list5

list5 = addListInList(list5)
print(list5)

#Problem 6
list6 = ["a", "b", ["c", ["d", "e", ["f", "g"], "k"], "l"], "m", "n"]
tempList = ["h", "i", "j"]
def addListInList(list6):
    for i in list6:
        if isinstance(i, list):
            addListInList(i)
        elif i == "g":
            list6 += tempList
    return list6
list6 = addListInList(list6)
print(list6)

#Problem 7
alist7 = [10, 20, 30, 40]
blist7 = [100, 200, 300, 400]
for i in range(0, len(alist7)):
    print(alist7[i], blist7[len(blist7) - i - 1])

#Problem 8
alist8 = ["M", "na", "i", "Ke"]
blist8 = ["y", "me", "s", "lly"]
list8 = []
for i in range(0, len(alist8)):
    list8.append(concat(alist8[i], blist8[i]))
print(list8)

#Problem 9
list9 = [1, 2, 3, 4, 5, 6, 7]
for i in range(0, len(list9)):
    list9[i] = pow(list9[i], 2)
print(list9)

#Problem 10
list10 = []
phrase = "The best class in Greenhill is Data Science"
for i in phrase.split(" "):
    list10.append(i.strip())
print(list10)