#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    const int N = 8;
    int num_cases;
    cin >> num_cases;

    for (int case_nr = 0; case_nr < num_cases; case_nr++) {
        pair<int, int> static_queen_pos;

        cin >> static_queen_pos.first >> static_queen_pos.second;
        static_queen_pos.first--;
        static_queen_pos.second--;
        int grid[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                grid[i][j] = 0;
            }
        }
        grid[static_queen_pos.first][static_queen_pos.second] = 1;
        vector<vector<int>> solutions;

        auto print_grid = [&]() -> void {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << grid[i][j] << " ";
                }
                cout << '\n';
            }
            cout << '\n';
        };
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
            if (r == static_queen_pos.first) {
                search(r + 1, 0);
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
        sort(solutions.begin(), solutions.end());

        if (case_nr > 0) cout << '\n';
        cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";

        for (int i = 0; i < solutions.size(); i++) {
            cout << setw(2) << i + 1 << "     ";
            for (int r: solutions[i]) {
                cout << " " << r + 1;
            }
            cout << '\n';
        }
    }
    return 0;
}