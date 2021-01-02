from z3 import *

s = Solver()

for i in range(20):
    globals()['a%i' % i] = BitVec('a%i' % i, 32)
    # Ensure only ASCII input
    s.add(globals()['a%i' % i] >= 48)
    s.add(globals()['a%i' % i] <= 122)

s.add(a0+a1+a2+a3+a4+a5+a6+a7+a8+a9+a10+a11+a12+a13+a14+a15+a16+a17+a18+a19 == 0x5f4)
s.add(a0  == ord("H"))
s.add(a6  == ord("4"))
s.add(a12 == ord("M"))
s.add(a18 == ord("A"))
s.add(a4 == ord("_"))
s.add(a9 == ord("_"))
s.add(a14 == ord("_"))

print s.check()
print s.model()
modl = s.model()
res=""
for i in range(20):
    obj = globals()['a%i' % i]
    c = modl[obj].as_long()
    res = res + chr(c)
print res

#H01@_040q_r0M8_Ko`Ag