import sys
from collections import deque, defaultdict

lines = deque(sys.stdin.read().splitlines())
case_count = 1

while lines:
    NC = int(lines.popleft())
    
    if NC == 0:
        break
    
    network, handled_count = defaultdict(list), 0
    starts = []
    
    while True:
        data = lines.popleft().split()
        data = [(a, b) for a, b in zip(data[::2], data[1::2])]
        
        for a, b in data:
            if handled_count < NC:
                network[a].append(b)
                network[b].append(a)
                handled_count += 1
            elif a == '0' and b == '0':
                lines.popleft()
                break
            else:
                starts.append((a, int(b)))
        else:
            continue
        break
    
    for start_node, ttl in starts:
        reachable = set()
        n_to_max_ttl = defaultdict(lambda: 0)
        
        queue = deque([(start_node, ttl)])
        
        while queue:
            cnode, cttl = queue.popleft()
            reachable.add(cnode)
            n_to_max_ttl[cnode] = cttl if cttl > n_to_max_ttl[cnode] else n_to_max_ttl[cnode]
            
            if cttl > 0:
                for n in network[cnode]:
                    if cttl > n_to_max_ttl[n]:
                        queue.append((n, cttl - 1))
                        n_to_max_ttl[n] = cttl

        unreached = set(network.keys()) - reachable
        print(f"Case {case_count}: {len(unreached)} nodes not reachable from node {start_node} with TTL = {ttl}.")
        case_count += 1