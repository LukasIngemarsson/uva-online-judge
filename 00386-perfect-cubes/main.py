from itertools import combinations

def main():
    rhs_to_combs = {}
    for b, c, d in combinations(range(2, 200), 3):
        rhs = b**3 + c**3 + d**3
        if not rhs in rhs_to_combs:
            rhs_to_combs[rhs] = []
        rhs_to_combs[rhs].append((b, c, d))


    for a in range(2, 200 + 1):
        if a**3 not in rhs_to_combs:
            continue
        for b, c, d in rhs_to_combs[a**3]:
            print(f"Cube = {a}, Triple = ({b},{c},{d})")


if __name__ == "__main__":
    main()
