import sys
from collections import deque, defaultdict

lines = deque(sys.stdin.read().splitlines())
nr_of_cases = int(lines.popleft())

for _ in range(nr_of_cases):
    n, m, l = [int(ch) for ch in lines.popleft().split()]
    connections = defaultdict(list)
    
    for _ in range(m):
        x, y = lines.popleft().split()
        connections[x].append(y)
    
    knocked_over = set()
    
    for _ in range(l):
        start = lines.popleft()
        
        if start in knocked_over:
            continue
        
        falling = deque([start])
        
        while falling:
            curr = falling.popleft()
                        
            if curr in knocked_over:
                continue
            
            knocked_over.add(curr)
            
            if curr in connections:
                falling.extend(connections[curr])
    
    print(len(knocked_over))