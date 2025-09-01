

def main():
    words = ["one", "two", "three"]
    n = int(input())

    for _ in range(n):
        s = input()
        for i, w in enumerate(words):
            cnt = 0
            for c1, c2 in zip(s, w):
                if c1 == c2:
                    cnt += 1
            
            if cnt >= len(w) - 1:
                print(i + 1)
                break


if __name__ == "__main__":
    main()

