from Crypto.Util.number import inverse

keys1=[13,12,6,15,3,15,5,9,1,11,12,15,13,6,7,7,15,3,15,5,9,13,12,6,15,13,6,7]
#keys2=[8,3,10,5,12,6,8,11,7,4,15,3,4,10,9,5,12,15,7,7,15,14,3,15,4,4,10,8] 
a=[]
i=len(keys1)-1
while i>3:
    if(len(a)>27):
        break
    a.append(inverse(keys1[i-3],17))
    a.append(-keys1[i-2]%16)
    a.append(-keys1[i-1]%16)
    a.append(inverse(keys1[i],17))
    a.append(keys1[i-5])
    a.append(keys1[i-4])
    i-=6

a.append(inverse(keys1[0],17))
a.append(-keys1[1]%16)
a.append(-keys1[2]%16)
a.append(inverse(keys1[3],17))
print(keys1)
print(a)