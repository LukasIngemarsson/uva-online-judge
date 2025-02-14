import sys
from collections import deque

lines = deque(sys.stdin.read().splitlines()[::2])

nr_of_cases = int(lines.popleft())

for nr in range(nr_of_cases):
    if nr > 0:
        print()
    
    line = lines.popleft()
    length = len(line)
    
    for i, ch in enumerate(line):
        if length % (i + 1) != 0:
            continue
        
        if line[:i+1] * int(length / (i + 1)) == line:
            print(i + 1)
            break