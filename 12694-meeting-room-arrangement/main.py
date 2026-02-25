import sys


def main():
    in_iter = iter(sys.stdin.read().split())

    N = int(next(in_iter))
    for _ in range(N):
        events = []
        while True:
            s = int(next(in_iter))
            f = int(next(in_iter))
            if s == 0 and f == 0:
                break
            events.append((s, f)) 
        events.sort(key=lambda x: x[1])
        cur_end = -1
        ans = 0
        for s, f in events:
            if s >= cur_end:
                cur_end = f
                ans +=1
        print(ans)


if __name__ == "__main__":
    main()

