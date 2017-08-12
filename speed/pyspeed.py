#!/usr/bin/env python
x = 1
while x <= 14:
    y = 14 - x
    print str(x) + "|" + str(y)
    if x**2 + y**2 == 100:
        print "match"
    x = x + 1
