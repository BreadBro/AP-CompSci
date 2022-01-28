import os, sys, csv
os.system("cls")

if len(sys.argv) != 3:
    print("Invalid Arguments.")
    exit()

try:
    dataFile = open("dna/databases/%s" %sys.argv[1])
    dnaFile = open("dna/sequences/%s" %sys.argv[2])
except Exception:
    print("File name(s) invalid.")
    exit()

file = csv.reader(dataFile)
data = []
unknownData = ["No match"]
header = next(file)

for i in file:
    data.append(i)

unknown = next(dnaFile)
for i in range(1, len(header)):
    unknownData.append(unknown.count(header[i]))

name = ""
for i in range(0, len(data)):
    temp = 0
    for j in range(1, len(header)):  
        if unknownData[j] == int(data[i][j]):
            temp += 1
            
    if (temp == (len(header) - 1)):
        unknownData[0] = data[i][0]
        break
        
print("The person with this DNA sequence is:", unknownData[0])
sys.argv = []