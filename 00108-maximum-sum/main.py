

def main():
    N = int(input())

    matrix_vals = []
    while len(matrix_vals) < N**2:
        matrix_vals.extend(list(map(int, input().split())))
    matrix = [matrix_vals[i:i+N] for i in range(0, N**2, N)] 

    max_sum = float("-inf")
    for u_r in range(N):
        temp = [0 for _ in range(N)]
        for l_r in range(u_r, N):
            for c in range(N):
                temp[c] += matrix[l_r][c]

            sum_ = temp[0]
            best_sum = temp[0]
            for x in temp[1:]:
                sum_ = max(x, sum_ + x)
                best_sum = max(best_sum, sum_)

            max_sum = max(max_sum, best_sum)

    print(max_sum) 


if __name__ == "__main__":
    main()

