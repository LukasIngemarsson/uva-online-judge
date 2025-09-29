

def main():
    while True:
        try:
            n = int(input())
            p = int(input())

            print(round(p ** (1 / n)))
        except:
            break


if __name__ == "__main__":
    main()
