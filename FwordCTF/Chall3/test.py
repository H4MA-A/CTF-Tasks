from pwn import *

file = open("out","rb")
a=file.read()
#print(a[4977:5000])
newfile=a[:4854]+p16(300)+a[4856:4891]+p8(3)+a[4892:4893]+p16(300)+a[4895:4939]+p16(300)+a[4941:4977]+p16(300)+a[4979:]
bin=open("newout","wb")
bin.write(newfile)