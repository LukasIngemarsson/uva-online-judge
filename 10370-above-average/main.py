

def main():
    C = int(input())

    for _ in range(C):
        grades = list(map(float, input().split()))
        grades.pop(0)
        n = len(grades)
        avg = sum(grades) / n
        above_avg = len([g for g in grades if g > avg])
        print(f"{(100 * above_avg / n):.3f}%")


if __name__ == "__main__":
    main()
