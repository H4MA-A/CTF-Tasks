from pwn import *
from z3 import *
import random

#flag="Reverse-engineering is used for many purposes: as a learning tool; as a way to make new, compatible products that are cheaper than what's currently on the market; for making software interoperate more effectively or to bridge data between different operating systems or databases; and to uncover the undocumented features of commercial products. Reverse Engineering in a CTF is typically the process of taking a compiled (machine code,bytecode) program and converting it back into a more human readable formatso you can read the flag which is:FwordCTF{W0W_4r3_Y0u_4_r0b0t?!}.Very often the goal of a reverse engineering challenge is to understand the functionality of a given program such that you can identify deeper issues.Assembly/Machine Code The C Programming Language Disassemblers Decompilers."
flag="VPVGL2gI1JXDKRGFiXu0vo8IfD9H7cJJxcQTaHgcfYeEPWM0Zr5gcPSCYmVdRGmfaWJ5LiXZm3tOkZqjftZChjVDxvIRvfr0vSQSQVde1iCnghgETVxA8ZBvp81Fn2sWLtQJ5rjDOk07hg2tXb25mbqEFvizhg6yVucm93d9DXxD8ravHVeudANWrXlXGWokyrKLetD2Zr5dhSc42dD6LPbE8oAFgo5xga9LQSLfWbbuBNfJhVf2kDg1gUIyKdXPsQsqQpZ2pX59Ym3GmpA6zhJe37xoZLSPwrkNShq0SUm5gcZ9PBKAC40auNu9Dzs0nNYvGiLIkmPYJagbGBWy8L7Fk4APAVYz6a7cFRQsRukkLCOP3CyA5YyzinlJMI3b1a9gtD63qifRaSUCHmK2KvOESF9I0XSZPAHfp72FAZhPFwordCTF{4r3_Y0u_4_r0b0t}P2aNT6KqIyaBdLy43mrI4qX2UkOe3bGIfi5xGGGVnLUhcYQ5nzufy9LcOGSI0tYn97Wc03Or39p8fF2VfR34cLm2XghPt4FadcelMMj4eVHShF3gGv8CpVf2QGA5gDT3t33xkKdlUfFKXeShnVXwSjClwlpzMSOqZOuVTWX1fb1T1Zg7Zf0J6507z3bKV1V9PXkRguIrpSTt0h2AbHdmkZ1ZiMmBfK7KiZ1jRALr1zvNRskh9tpRQDTZ5j2XcCtDCvb2UBvrxEW2mU9OnQlk1368wzfbFAVsLfbn0F0HP6iS52Olv40jKOXTQoU0clQqnZ6TcHnFq4HaLpeu6t5i6yZflHh"
f=[]
a1=[]
a2=[]
r=[]
x=[]
p=[]

for i in flag:
	f.append(ord(i))

i=0
j=0
while i < len(f):
	a1.append(random.randint(0,1000))
	a2.append(random.randint(0, 2))
	r.append((f[i]+a1[j]+f[i+1])>>a2[j])
	x.append(f[i]+(f[i]^f[i+1]))
	p.append(f[i]*f[i+1])
	i+=2
	j+=1

file = open("out","rb")
a=file.read()
num=0
file_name="out"
for i in range(400):
	newfile=a[:4854]+p16(a1[i])+a[4856:4891]+p8(a2[i])+a[4892:4893]+p16(r[i])+a[4895:4939]+p16(x[i])+a[4941:4977]+p16(p[i])+a[4979:]
	fich=file_name+str(num).zfill(3)
	bin=open(fich,"wb")
	bin.write(newfile)
	num+=1

###Solver
'''
s =Solver()
for i in range(len(f)):
    globals()['b%i' % i] = BitVec('b%i' % i, 32)
    # Ensure only ASCII input
    s.add(globals()['b%i' % i] > 31)
    s.add(globals()['b%i' % i] < 126)

#for i in range(len(f)):
i=0
j=0
while i < len(f):
	a=i+1
	s.add(( globals()['b%i' % i]+a1[j]+ globals()['b%i' % a]) >> a2[j] == r[j])
	s.add(globals()['b%i' % i] +(globals()['b%i' % i] ^ globals()['b%i' % a]) == x[j])
	s.add(globals()['b%i' % i] * globals()['b%i' % a] == p[j])
	i+=2
	j+=1

print(s.check())
modl = s.model()
res=""
for i in range(len(f)):
    obj = globals()['b%i' % i]
    c = modl[obj].as_long()
    res = res + chr(c)
print(res)'''