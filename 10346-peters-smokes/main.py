

def main():
    while True:
        try:
            n, k = map(int, input().split())
        except:
            break

        smoked = n
        r = n
        while r >= k:
            smoked += r // k
            r = r // k + r % k 

        print(smoked)


if __name__ == "__main__":
    main()
