import sys

def find_opt(m, n, t):
    time_spent, total = 0, 0
    
    while True:
        new_time = time_spent + m
        
        if new_time > t:
            break
        
        time_spent += m
        total += 1
        
        if new_time == t:
            return (time_spent, total)
        
    opt = (time_spent, total)
    
    if m == n:
        return opt
    
    m_count = total
            
    while True:        
        new_time = time_spent + n
        
        if new_time > t:
            if m_count == 0:
                break
            
            m_count -= 1
            
            time_spent -= m
            total -= 1
            continue
            
        time_spent += n
        total += 1
    
        if time_spent > opt[0]:
            opt = (time_spent, total)
    
    return opt

lines = sys.stdin.read().splitlines()

for line in lines:
    m, n, t = [int(ch) for ch in line.split()]

    if n <= m:
        m, n = n, m

    time_spent, total = find_opt(m, n, t)
            
    out = f"{total}{(' ' + str(t - time_spent)) if time_spent < t else ''}"
    print(out)