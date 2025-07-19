#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <limits>
using namespace std;

class MatrixChainMultiplication {
public:
    int N;
    int* dims;
    int** m;
    int** s;

    MatrixChainMultiplication(int N) : N(N) {
        dims = new int[N+1];
        m = new int*[N+1];
        s = new int*[N+1];

        for (int i = 0; i <= N; i++) {
            m[i] = new int[N+1];
            s[i] = new int[N+1];

            for (int j = 0; j <= N; ++j) {
                m[i][j] = (i == j) ? 0 : numeric_limits<int>::max();
                s[i][j] = 0;
            }
        }
    }

    void calculate_optimal_sequence() {
        for (int len = 2; len <= N; len++) {
            for (int i = 1; i <= N - len + 1; i++) {
                int j = i + len - 1;

                for (int k = i; k <= j - 1; k++) {
                    int cost = m[i][k] + m[k+1][j] + dims[i-1] * dims[k] * dims[j];

                    if (cost < m[i][j]) {
                        m[i][j] = cost;
                        s[i][j] = k;
                    }
                }
            }
        }
    }

    void print_optimal_sequence(int i, int j) {
        if (i == j) {
            cout << "A" << i;
        }
        else {
            cout << "(";
            print_optimal_sequence(i, s[i][j]);
            cout << " x ";
            print_optimal_sequence(s[i][j] + 1, j);
            cout << ")";
        }
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int case_count = 1;

    while (true) {
        int N;
        cin >> N;

        if (N == 0) {
            break;
        }

        MatrixChainMultiplication mcm(N);

        for (int i = 0; i < N; i++) {
            long long r, c;
            cin >> r >> c;

            if (i == 0) {
                mcm.dims[0] = r;
                mcm.dims[1] = c;
            }
            else {
                mcm.dims[i+1] = c;
            }
        }
        cout << "Case " << case_count << ": ";
        case_count++;
        mcm.calculate_optimal_sequence();
        mcm.print_optimal_sequence(1, N);
        cout << '\n';
        // cout << mcm.m[1][N] << '\n';
    }
    return 0;
}