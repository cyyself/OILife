#!/usr/bin/env python3
from decimal import Decimal
a,b = map(str,input().split())
a = Decimal(a)
b = Decimal(b)
print(Decimal(a%b))
