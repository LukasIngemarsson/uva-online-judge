#include <bits/stdc++.h>
using namespace std;

pair<int, int> dirs[] = {{-1, -1}, {-1, 0}, {-1, 1},
                        {0, -1}, {0, 1},
                        {1, -1}, {1, 0}, {1, 1}};

char get_adj_mine_count(vector<string> &mine_grid, int n, int r, int c) {
    int count = 0;
    for (pair<int, int> &dir : dirs) {
        int adjr = r + dir.first, adjc = c + dir.second;
        if (adjr >= 0 && adjr < n && adjc >= 0 && adjc < n 
            && mine_grid[adjr][adjc] == '*') {
            ++count;
        }
    }
    return count + '0';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ++ti) {
        if (ti > 0) cout << '\n';
        int n;
        cin >> n;
        vector<string> mine_grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> mine_grid[i];
        }
        vector<string> touched_grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> touched_grid[i];
        }
        vector<string> out_grid(n, string(n, '.'));
        bool mine_hit = false;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (touched_grid[r][c] == 'x') {
                    if (mine_grid[r][c] == '*') mine_hit = true;
                    else out_grid[r][c] = get_adj_mine_count(mine_grid, n, r, c);
                }
            }
        }
        if (mine_hit) {
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (mine_grid[r][c] == '*') out_grid[r][c] = '*';
                }
            }
        }
        for (string &row : out_grid) {
            cout << row << '\n';
        }
    }
    return 0;
}