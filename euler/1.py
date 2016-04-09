#!/usr/bin/env python

ret = 0
for i in range(3,1000):
    print ret, i
    if i % 3 == 0 or i % 5 == 0:
        ret = ret + i
print ret
