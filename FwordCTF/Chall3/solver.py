from z3 import *
from pwn import *

a1=[]
a2=[]
r=[]
x=[]
p=[]

num=0
file_name="out"
for i in range(400):
    fich=file_name+str(num).zfill(3)
    file=open(fich,"rb")
    a=file.read()
    a1.append(u16(a[4854:4856]))
    a2.append(a[4891])
    r.append(u16(a[4893:4895]))
    x.append(u16(a[4939:4941]))
    p.append(u16(a[4977:4979]))
    #newfile=a[:4854]+p16(a1[i])+a[4856:4891]+p8(a2[i])+a[4892:4893]+p16(r[i])+a[4895:4939]+p16(x[i])+a[4941:4977]+p16(p[i])+a[4979:]
    num+=1

s =Solver()
for i in range(800):
    globals()['b%i' % i] = BitVec('b%i' % i, 32)
    # Ensure only ASCII input
    s.add(globals()['b%i' % i] > 31)
    s.add(globals()['b%i' % i] < 126)

#for i in range(len(f)):
i=0
j=0
while i < 800:
	a=i+1
	s.add(( globals()['b%i' % i]+a1[j]+ globals()['b%i' % a]) >> a2[j] == r[j])
	s.add(globals()['b%i' % i] +(globals()['b%i' % i] ^ globals()['b%i' % a]) == x[j])
	s.add(globals()['b%i' % i] * globals()['b%i' % a] == p[j])
	i+=2
	j+=1

print(s.check())
modl = s.model()
res=""
for i in range(800):
    obj = globals()['b%i' % i]
    c = modl[obj].as_long()
    res = res + chr(c)
print(res)
