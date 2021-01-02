#func =(0x40,0xdeadbeef)

a=0x40
b=0xdeadbeef
sum=0
for i in range(a):
	if i%2==0:
		sum+=i
sum+=b

print hex(sum)

#flag:
#Securinets{0xdeadc2cf}