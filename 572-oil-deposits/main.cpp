#include <bits/stdc++.h>
using namespace std;

int m, n;
pair<int, int> dirs[8] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

void dfs(vector<vector<char>>& grid, int r, int c) {    
    grid[r][c] = '.';
    for (auto& dir_ : dirs) {
        int newr = r + dir_.first, newc = c + dir_.second;
        if (newr < 0 || newr >= m || newc < 0 || newc >= n) continue;
        if (grid[newr][newc] == '@') {
            dfs(grid, newr, newc);
        }
    }    
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    while (true) {
        cin >> m >> n;
        if (!m && !n) break;
        vector<vector<char>> grid(m, vector<char>(n, '.'));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                cin >> grid[r][c];
            }
        }    
        int deposit_count = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] != '@') continue;
                dfs(grid, r, c);
                ++deposit_count;
            }
        }    
        cout << deposit_count << '\n';
    }        

    return 0;
}
