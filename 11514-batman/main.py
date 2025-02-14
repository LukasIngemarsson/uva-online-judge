import sys
from collections import deque

def batman_can_do_it(superpowers, d_factors, levels, P, V, E):
    node_to_top_stamina = dict()
    
    def dfs(curr_node):
        if curr_node in node_to_top_stamina:
            return node_to_top_stamina[curr_node]
        
        level_i, sp_i = curr_node
        
        next_level_i = level_i + 1
        min_stamina = 10 ** 8 + 1
        following_sp_i = sp_i + 1
        
        if following_sp_i < P:
            sp2, a_factor, cost = superpowers[following_sp_i]
            
            if sp2 in levels[next_level_i] and a_factor >= d_factors[next_level_i]:
                if next_level_i == V - 1:
                    min_stamina = min(min_stamina, cost)
                else:
                    min_stamina = min(min_stamina, cost + dfs((next_level_i, following_sp_i)))
            min_stamina = min(min_stamina, dfs((level_i, following_sp_i)))
            
        node_to_top_stamina[curr_node] = min_stamina
        return min_stamina

    sp_list = [x[0] for x in superpowers]
    for sp in levels[0]:
        sp_i = sp_list.index(sp)
        cost = superpowers[sp_i][2] 
        start_node = (0, sp_i)            
        min_stamina = dfs(start_node) + cost
        
        if min_stamina <= E:
            return True
    return False
            

lines = deque(sys.stdin.read().splitlines())

while True:
    P, V, E = map(int, lines.popleft().split())
    if P == 0 and V == 0 and E == 0:
        break
    
    superpowers = []
    for i in range(P):
        s, a, c = lines.popleft().split()
        a, c = int(a), int(c)
        
        superpowers.append((s, a, c))
        
    levels, d_factors = [], []
    for _ in range(V):
        _, d, aff_by = lines.popleft().split()
        d, aff_by = int(d), aff_by.split(',')
        
        levels.append(aff_by)
        d_factors.append(d) 

    if batman_can_do_it(superpowers, d_factors, levels, P, V, E):
        print("Yes")
    else:
        print("No")