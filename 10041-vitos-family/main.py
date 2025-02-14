import sys
from collections import deque

lines = deque(sys.stdin.read().splitlines())
nr_of_cases = int(lines.popleft())

for _ in range(nr_of_cases):
    chars = lines.popleft().split()
    r, S = int(chars[0]), sorted([int(s) for s in chars[1:]])  
                
    median_s = S[r//2]
    
    min_sum = sum([abs(median_s - s) for s in S])
    print(min_sum)