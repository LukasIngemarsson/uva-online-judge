#include <bits/stdc++.h>
using namespace std;

int m, n;
int hole_size = 0;
char hole_char = '.';
pair<int, int> dirs[4] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(vector<vector<char>>& grid, int r, int c) {    
    grid[r][c] = '.';
    ++hole_size;
    for (auto& dir_ : dirs) {
        int newr = r + dir_.first, newc = c + dir_.second;
        if (newr < 0 || newr >= m || newc < 0 || newc >= n) continue;
        if (grid[newr][newc] == hole_char) {
            dfs(grid, newr, newc);
        }
    }    
}

bool custom_comp(pair<char, int> a, pair<char, int> b) {
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (true) {
        cin >> m >> n;
        if (!m && !n) break;
        vector<vector<char>> grid(m, vector<char>(n, '.'));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                cin >> grid[r][c];
            }
        }          
        vector<pair<char, int>> holes;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '.') continue;
                hole_char = grid[r][c];
                dfs(grid, r, c);
                holes.push_back({hole_char, hole_size});
                hole_size = 0;
            }
        }    
        cout << "Problem " << t++ << ":\n";
        if (!holes.empty()) {
            sort(holes.begin(), holes.end(), custom_comp);
            for (auto& p : holes) {
                cout << p.first << " " << p.second << '\n';
            }
        }
    } 

    return 0;
}