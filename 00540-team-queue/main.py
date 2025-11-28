from collections import deque, defaultdict


def main():
    scn = 1
    while True:
        t = int(input())
        if t == 0:
            break

        elem_to_team = {}
        for i in range(t):
            elems = input().split()[1:]
            for elem in elems:
                elem_to_team[elem] = i

        print(f"Scenario #{scn}")

        team_dq = deque() 
        team_to_dq = defaultdict(deque)
        while True:  
            args = input().split()

            if len(args) == 1:
                if args[0] == "STOP":
                    break
                elif args[0] == "DEQUEUE":
                    team = team_dq[0]
                    head = team_to_dq[team].popleft() 

                    if len(team_to_dq[team]) == 0:
                        team_dq.popleft()
                        del team_to_dq[team]

                    print(head)
                else:
                    raise ValueError
            elif len(args) == 2:
                assert args[0] == "ENQUEUE"

                elem = args[1]
                team = elem_to_team[elem]

                if team not in team_to_dq:
                    team_dq.append(team)
                team_to_dq[team].append(elem)
            else:
                raise ValueError

        scn += 1
        print()


if __name__ == "__main__":
    main()

