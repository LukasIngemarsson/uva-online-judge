import sys
from decimal import Decimal, getcontext

getcontext().prec = 100

with sys.stdin as f:
    for line in f:
        R, n = map(Decimal, line.strip().split())
        R_pow_n = format(R**n, 'f')
        if R_pow_n.startswith('0.'): R_pow_n = R_pow_n[1:] 
        R_pow_n = R_pow_n.rstrip('0').rstrip('.')
        print(R_pow_n)