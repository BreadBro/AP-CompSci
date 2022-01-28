import os, csv
os.system("cls")

def checkNum(fullNum):
    length = 0
    arr = []
    sum = 0
    for i in str(fullNum):
        arr.append(int(i))
        length += 1

    if length != 13 and length != 15 and length != 16:
        return 0
    if length % 2 == 1:
        for i in range(0, length):
            if i % 2 == 0:
                sum += arr[i]
            else: 
                if (arr[i] * 2) > 9:
                    sum += (arr[i] * 2) % 10 + 1
                else:
                    sum += arr[i] * 2
    else:
        for i in range(0, length):
            if i % 2 == 1:
                sum += arr[i]
            else: 
                if (arr[i] * 2) > 9:
                    sum += (arr[i] * 2) % 10 + 1
                else:
                    sum += arr[i] * 2
        

    if sum % 10 != 0:
        return 0
    
    if length == 15:
        if arr[0] == 3 and (arr[1] == 4 or arr[1] == 7):
            return 1
    if length == 16 or length == 13:
        if arr[0] == 5 and arr[1] >= 1 and arr[1] <= 6:
            return 2
        if arr[0] == 4:
            return 3
    return 0

def main():
    cardNum = 0
    while cardNum <= 0:
        try:
            cardNum = int(input("Credit Card Number: "))
        except Exception:
            print("Not a number. ")
    
    #1 = AMEX, 2 = MASTERCARD, 3 = VISA
    cardType = checkNum(cardNum)
    if (cardType == 1):
        print("AMEX")
    elif (cardType == 2):
        print("MASTERCARD")
    elif (cardType == 3):
        print("VISA")
    else:
        print("Invalid. ")

main()