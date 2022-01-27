import os, csv
os.system("cls")

try:
    file = open("insurance_data.csv")
except Exception:
    print("Waaah")
print(type(file))
insuranceFile = csv.reader(file)
header = next(insuranceFile)
print(header)
insuranceData = []
# 0 - age, 1 - sex, 2 - bmi, 3 - children, 4 - smoker
for i in insuranceFile:
    if "female" in i[1]:
        i[1] = 0
    else:
        i[1] = 1
    if "y" in i[4]:
        i[4] = 1
    else:
        i[4] = 0
    cost = 250 * int(i[0]) - 128 * int(i[1]) + 370 * float(i[2]) + 425 * int(i[3]) + 24000 * int(i[4]) - 12500
    i.append(round(cost, 2))
    insuranceData.append(i)
    print(i)
# cost = 250*age - 128 * sex + 370 * bmi + 425 * num + 24000 * smoker - 12500

nwAVG = 0
count = 0
for i in insuranceData:
    if "northwest" in i[5]:
        nwAVG += i[7]
        count += 1

print("NW average: %.2f" %(nwAVG/count))
file.close()
# Can't edit files on school laptop with vsc
#fileName = "insurance_data_edited.csv"
#fields = ["age", "sex", "bmi", "children", "smoker", "region", "charges", "total"]
#with open(fileName, "w") as csvfile:
#    csvwriter = csv.writer(csvfile)
#    csvwriter.writerow(fields)
#    for i in range(0, len(insuranceData)):
#        csvwriter.writerow(insuranceData[i])