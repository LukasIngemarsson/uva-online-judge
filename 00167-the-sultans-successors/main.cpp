#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    const int N = 8;
    int k;
    cin >> k;

    for (int cnr = 0; cnr < k; cnr++) {
        int board_values[N][N];
        int grid[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board_values[i][j];
                grid[i][j] = 0;
            }
        }

        vector<vector<int>> solutions;

        auto is_valid_state = [&](int r, int c) -> bool {
            for (int i = 0; i < N; i++) { // check column
                if (i == r) continue;

                if (grid[i][c] == 1) return false;
            }
            for (int i = 1; r + i < N && c + i < N; i++) {  // down-right
                if (grid[r+i][c+i] == 1) return false;
            }
            for (int i = 1; r - i >= 0 && c - i >= 0; i++) {  // up-left
                if (grid[r-i][c-i] == 1) return false;
            }
            for (int i = 1; r + i < N && c - i >= 0; i++) {  // down-left
                if (grid[r+i][c-i] == 1) return false;
            }
            for (int i = 1; r - i >= 0 && c + i < N; i++) {  // up-right
                if (grid[r-i][c+i] == 1) return false;
            }
            return true;
        };
        function<void(int, int)> search;

        search = [&](int r, int c) -> void {
            if (r > N - 1) {
                vector<int> sol;

                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if (grid[j][i] == 1) { // go along column
                            sol.push_back(j);
                            break;
                        }
                    }
                }
                solutions.push_back(sol);
                return;
            }
            if (is_valid_state(r, c)) {
                grid[r][c] = 1;
                search(r + 1, 0);
                grid[r][c] = 0;
            }
            if (c < N - 1) search(r, c + 1);
        };
        search(0, 0);

        int ans = 0;
        for (int i = 0; i < solutions.size(); i++) {
            int sum = 0;
            for (int r = 0; r < solutions[i].size(); r++) {
                sum += board_values[r][solutions[i][r]]; 
            }
            ans = max(ans, sum);
        }
        cout << setw(5) << ans << '\n';
    }
    return 0;
}
