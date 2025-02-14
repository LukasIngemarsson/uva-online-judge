import sys
from collections import deque

def does_overlap(tasks):
    slots = [False for _ in range(10 ** 6)]
    
    for start, end, rep in tasks:
        for i in range(0, 10 ** 6 - end, rep):            
            for j in range(start + i, end + i):
                if slots[j]:
                    # print("overlap", j)
                    return True
                
                slots[j] = True
    return False


lines = deque(sys.stdin.read().splitlines())

while True:
    n, m = [int(ch) for ch in lines.popleft().split()]
    
    if n == 0 and m == 0:
        break
    
    tasks = []
    
    for _ in range(n):
        a, b = [int(ch) for ch in lines.popleft().split()]
        tasks.append((a, b, 10 ** 6))
            
    for _ in range(m):
        a, b, rep = [int(ch) for ch in lines.popleft().split()]
        
        tasks.append((a, b, rep))
        
    if does_overlap(tasks):
        print("CONFLICT")
    else:
        print("NO CONFLICT")