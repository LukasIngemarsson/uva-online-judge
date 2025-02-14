#include <bits/stdc++.h>
using namespace std;

struct Solver {
    vector<vector<int>> grid, res;
    int L, C, sr, sc;
    int move_count = 0;

    Solver(int L, int C) : grid(L + 1, vector<int>(C + 1, 0)), 
                            res(L + 1, vector<int>(C + 1, INT_MAX)), L(L), C(C) {
        int P = 2 * C;
        for (int _ = 0; _ < 2 * P; ++_) {
            int r, c;
            cin >> r >> c;
            grid[r][c] = 1;
        }
        cin >> sr >> sc;
    }

    void print_sol() {
        for (int ri = L; ri >= 1; --ri) {
            for (int ci = 1; ci <= C; ++ci) {
                if (!(ri == sr && ci == sc) && res[ri][ci] < INT_MAX) {
                    cout << ri << " " << ci << " " << res[ri][ci] << '\n';
                }
            }
        }
    }

    void find_sol() {
        if (sr < L && !grid[sr+1][sc]) res[sr+1][sc] = 1;
        if (sc > 1 && !grid[sr][sc-1]) res[sr][sc-1] = 1;
        if (sc < C && !grid[sr][sc+1]) res[sr][sc+1] = 1;
        search(sr, sc);
    }

    void search(int r, int c) {
        if (move_count < res[r][c]) res[r][c] = move_count;
        ++move_count;
        if (r < L - 1) {
            if (grid[r+1][c] and !grid[r+2][c]) search(r+2, c);
            if (c < C - 1 && grid[r+1][c+1] && !grid[r+2][c+2]) search(r+2, c+2);
            if (c > 1 && grid[r+1][c-1] && !grid[r+2][c-2]) search(r+2, c-2);
        }
        if (sc > 2 && grid[r][c-1] && !grid[r][c-2]) search(r, c-2);
        if (sc < C - 1 && grid[r][c+1] && !grid[r][c+2]) search(r, c+2);
        --move_count;   
    }
};

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    int L, C;
    bool first_iter = true;
    while (cin >> L >> C) {
        if (first_iter) {
            first_iter = false;
        }
        else {
            cout << '\n';
        }
        Solver solver(L, C);
        solver.find_sol();
        solver.print_sol();
    }
    return 0;
}