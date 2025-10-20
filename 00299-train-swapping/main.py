

def main():
    N = int(input())
    for _ in range(N):
        L = int(input())
        arr = list(map(int, input().split()))

        swaps = 0
        for i in range(L, 0, -1):
            for j in range(1, i):
                if arr[j-1] > arr[j]:
                    arr[j-1], arr[j] = arr[j], arr[j-1]
                    swaps += 1
        print(f"Optimal train swapping takes {swaps} swaps.") 


if __name__ == "__main__":
    main()

