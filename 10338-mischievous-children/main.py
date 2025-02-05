import sys
from collections import Counter
from math import factorial

lines = [l.strip() for l in sys.stdin.readlines()]

for t, s in enumerate(lines):
    if t == 0: continue
    cntr = Counter(s)
    num = factorial(len(s))
    denom = 1
    for cnt in cntr.values():
        denom *= factorial(cnt)
    print(f"Data set {t}: {num // denom}")