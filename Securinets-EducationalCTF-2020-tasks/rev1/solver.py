enc="Sdavvlhb|zq:Sa?d#NE{ AIBG^*O=<c"
flag=""

for i in range(len(enc)):
	flag+= chr(ord(enc[i])^i)
print flag