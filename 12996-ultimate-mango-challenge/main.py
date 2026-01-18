import sys


def main():
    lines = iter(sys.stdin.read().splitlines())
    T = int(next(lines))
    for t in range(1, T + 1):
        _, L = map(int, next(lines).split())
        mangos = map(int, next(lines).split())
        limits = map(int, next(lines).split())
        tot = 0
        valid = False
        for m, l in zip(mangos, limits):
            if m > l:
                break
            tot += m
            if tot > L:
                break
        else:
            valid = True
        print(f"Case {t}: {'Yes' if valid else 'No'}")


if __name__ == "__main__":
    main()

