import random
import os
import string
os.system("") 

deck = []
player1 = []
player2 = []
def main():
    name = input("What is your name? ")
    createDeck()
    playerCards()
    print(deck)
    winner = play()
    print(player1)
    print()
    print(player2)

    if (winner == 0):
        print("Congratulations, " + name + ", you won!")
    else:
        print("The computer is the winner.")
    

def checkVal(temp):
    temp = str(temp)
    temp.replace(" ", "")
    try:
        return int(temp)
    except Exception:
        if temp == str("A "):
            return 1
        if temp == str("K "):
            return 13
        if temp == str("Q "):
            return 12
        if temp == str("J "):
            return 11

def play():
    global player1
    global player2
    lengthP1 = len(player1)
    lengthP2 = len(player2)
    count = 0
    while((lengthP1 != 0 and lengthP2 != 0) or (lengthP1 == 30 or lengthP2 == 30)):
        temp1 = str(player1[count][:2])
        temp2 = str(player2[count][:2])
        input("Press enter to draw! ")
        print(temp1, ": ", temp2)
        temp1 = checkVal(temp1)
        temp2 = checkVal(temp2)
        if temp1 > temp2:
            player1.append(player1[count])
            player1.append(player2[count])
            player1.remove(player1[count])
            player2.remove(player2[count])
            lengthP1 += count + 1
            lengthP2 -= count + 1

        if temp1 < temp2:
            player2.append(player2[count])
            player2.append(player1[count])
            player2.remove(player2[count])
            player1.remove(player1[count])
            lengthP2 += count + 1
            lengthP1 -= count + 1

        if temp1 == temp2:
            while(1):
                x = 1
                count += 1
                print(count)
                temp1 = str(player1[count][:2])
                temp2 = str(player2[count][:2])
                input("It's a tie! Draw again.")
                print(temp1, ": ", temp2)
                
                temp1 = checkVal(temp1)
                temp2 = checkVal(temp2)

                if lengthP1 - count < 0:
                    return 1

                if lengthP2 - count < 0:
                    return 0

                if temp1 > temp2:
                    for i in range(count, 0, -1):
                        player1.append(player1[i])
                        player1.append(player2[i])
                        player1.remove(player1[i])
                        player2.remove(player2[i])
                        
                    lengthP1 += count + 1
                    lengthP2 -= count + 1
                    count = 0
                    x = 2

                if temp1 < temp2:
                    for i in range(count, -1, -1):
                        player2.append(player2[i])
                        player2.append(player1[i])
                        player2.remove(player2[i])
                        player1.remove(player1[i])
                    
                    lengthP2 += count + 1
                    lengthP1 -= count + 1
                    count = 0
                    x = 2
                if (x != 1):
                    break 
    if lengthP1 > lengthP2:
        return 0

    else: 
        return 1

def createDeck():
    global deck
    suits = ["♥️", "♦️", "♣️", "♠️"]
    royals = ["J", "Q", "K", "A"]
    numberCards = []
    for i in range(2,11):
        numberCards.append(str(i))

    for j in range(4):
        numberCards.append(royals[j])

    for k in range(4):
        for l in range(13):
            card = (numberCards[l] + " " + suits[k])
            deck.append(card)

def playerCards():
    random.shuffle(deck)
    global player1
    global player2

    for l in range(52):
        if l % 2 == 0:
            player1.append(deck[l])

        else:
            player2.append(deck[l])

main()