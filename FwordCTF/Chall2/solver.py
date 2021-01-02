from Crypto.Util.number import inverse
import string

##flag
#enc=[4,6,7,7,6,15,7,2,6,4,4,3,5,4,4,6,7,11,6,14,3,0,7,4,5,15,3,4,5,15,6,2,6,1,6,4,5,15,6,9,6,4,3,3,6,1,5,15,3,4,6,6,7,4,3,3,7,2,5,15,4,1,6,12,6,12,7,13]
##encrypted
enc=[8, 7, 2, 1, 2, 7, 10, 12, 5, 5, 9, 15, 9, 8, 2, 2, 5, 5, 0, 3, 1, 1, 11, 13, 3, 10, 8, 8, 6, 8, 15, 13, 4, 11, 11, 9, 4, 14, 10, 10, 10, 3, 11, 10, 14, 7, 2, 7, 15, 11, 12, 13, 0, 3, 0, 11, 12, 2, 6, 7, 10, 7, 7, 0, 15, 5, 15, 4]
flag=[]
###test
keys1=[13, 12, 6, 15, 3, 15, 5, 9, 1, 11, 12, 15, 13, 6, 7, 7, 15, 3, 15, 5, 9, 13, 12, 6, 15, 13, 6, 7]
keys2=[8,3,10,5,12,6,8,11,7,4,15,3,4,10,9,5,12,15,7,7,15,14,3,15,4,4,10,8]
def mul(a,b):
	x=(a*b)%17
	if a==0:
		x=(16*b)%17
	if x==16:
		x=0
	return x
def round(x1,x2,x3,x4,k):
	j=0
	for i in range(4):
		aux1 = mul(x1,k[j])
		aux2 = (x2+k[j+1])%16
		aux3 = (x3+k[j+2])%16
		aux4 = mul(x4,k[j+3])
		aux5 = aux1^aux3
		aux6 = aux2^aux4
		aux7 = mul(aux5,k[j+4])
		aux8 = (aux6+aux7)%16
		aux9 = mul(aux8,k[j+5])
		auxa = (aux7+aux9)%16
		x1 = aux1^aux9
		x2 = aux2^auxa
		x3 = aux3^aux9
		x4 = aux4^auxa
		j+=6
	x1 = mul(x1,k[24])
	x2 = (x2+k[25])%16
	x3 = (x3+k[26])%16
	x4 = mul(x4,k[27])
	flag.append(x1)
	flag.append(x2)
	flag.append(x3)
	flag.append(x4)
i=0
while i<len(enc):
	round(enc[i],enc[i+1],enc[i+2],enc[i+3],keys2)
	i+=4
i=0
final_flag=""
while i<len(flag):
	final_flag+=chr(int(bin(flag[i])[2:].zfill(4)+bin(flag[i+1])[2:].zfill(4),2))
	i+=2

print(final_flag)