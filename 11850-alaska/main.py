import sys


def main():
    DAWSON_CITY = 1422
    FULL_TANK = 200
    in_iter = iter(sys.stdin.read().split())
    while True:
        n = int(next(in_iter))
        if n == 0:
            break
        locs = []
        for _ in range(n):
            locs.append(int(next(in_iter)))
            locs.append(2 * DAWSON_CITY - locs[-1])
        locs.sort()

        prev_loc = 0
        valid = True
        for d in locs:
            if d - prev_loc > FULL_TANK:
                valid = False
                break
            prev_loc = d
        print("POSSIBLE" if valid else "IMPOSSIBLE")


if __name__ == "__main__":
    main()
