#-------------------------------------------------------------------------------
# Purpose:     2020 컴퓨터및 프로그래밍 입문
# Author:      Cho
# Created:     2020-04-20
#-------------------------------------------------------------------------------

import random
import csv

count = 0


with open('AppleStock.csv', newline='') as afile:
#with open('small.csv', newline='') as afile:
    apple = list(csv.reader( afile))

print("Total days in apple stock recorded:",  len(apple) )

Applist = []
for w in apple :
    oneday= ( w[0], float(w[4]), int(w[5]) )
    Applist.append( oneday )

