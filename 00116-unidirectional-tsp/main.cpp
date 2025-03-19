#include <bits/stdc++.h>
using namespace std;

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    int m, n;
    while (cin >> m >> n) {
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                cin >> matrix[r][c];
            }
        }
        vector<vector<int>> state(m, vector<int>(n, INT_MAX));
        vector<vector<int>> paths(m, vector<int>(n, INT_MAX));
        vector<vector<int>> temp_paths(m);
        for (int r = 0; r < m; ++r) {
            state[r][0] = matrix[r][0];
            paths[r][0] = r;
        } 
        for (int c = 0; c < n - 1; ++c) {
            int newc = c + 1;
            for (int r = 0; r < m; ++r) {
                for (int roff = -1; roff <= 1; ++roff) {
                    int newr = (m + r + roff) % m;
                    int new_val = state[r][c] + matrix[newr][newc];
                    if (new_val < state[newr][newc] || new_val == state[newr][newc] && paths[r] < temp_paths[newr]) {
                        state[newr][newc] = new_val;
                        temp_paths[newr] = paths[r];
                        temp_paths[newr][newc] = newr;
                    }
                }
            }
            swap(temp_paths, paths);
        }
        int min_cost = INT_MAX;
        for (int r = 0; r < m; ++r)
            min_cost = min(min_cost, state[r][n-1]);
        vector<vector<int>> min_paths;
        for (int r = 0; r < m; ++r) {
            if (state[r][n-1] == min_cost)
                min_paths.push_back(paths[r]);
        }
        vector<int> min_lex_path = *min_element(min_paths.begin(), min_paths.end());
        for (int c = 0; c < n; ++c) {
            if (c > 0) cout << " ";
            cout << min_lex_path[c] + 1;
        }
        cout << '\n' << min_cost << '\n';
    }  

    return 0;
}