import heapq as heep





myheep=[]
lis=[55,32,455,1,3,5,3235,6,432,13,5,32]


for val in lis:
    heep.heappush(myheep,val)



print(myheep)

for step in range(len(myheep)):
    print(heep.heappop(myheep),end=",")