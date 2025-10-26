

def main():
    while True:
        try:
            k, n = map(int, input().split())
            boxes = [sorted(map(int, input().split())) + [i + 1] for i in range(k)]
            boxes.sort()

            dp = k * [1]
            prev = k * [-1]

            for i in range(k):
                for j in range(i):
                    if all(boxes[i][d] > boxes[j][d] for d in range(n)):
                        if dp[j] + 1 > dp[i]:
                            dp[i] = dp[j] + 1
                            prev[i] = j

            max_len = max(dp)
            idx = dp.index(max_len)
            seq = []
            while idx != -1:
                seq.append(boxes[idx][-1])
                idx = prev[idx]
            seq.reverse()

            print(max_len)
            print(*seq)

        except EOFError:
            break


if __name__ == "__main__":
    main()

