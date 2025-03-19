#include <bits/stdc++.h>
using namespace std;

string ans = "";

void decomp_dfs(vector<vector<int>>& bitmap, pair<int, int> rbound, pair<int, int> cbound) {
    if (rbound.first >= rbound.second || cbound.first >= cbound.second) return;
    int val = bitmap[rbound.first][cbound.first];
    bool needs_decomp = false;
    for (int r = rbound.first; r < rbound.second; ++r) {
        for (int c = cbound.first; c < cbound.second; ++c) {
            if (bitmap[r][c] != val) {
                needs_decomp = true;
                break;
            }
        }
    }
    if (needs_decomp) {
        ans += "D";
        int rline = (rbound.first + rbound.second + 1) / 2;
        int cline = (cbound.first + cbound.second + 1) / 2;
        decomp_dfs(bitmap, {rbound.first, rline}, {cbound.first, cline});
        decomp_dfs(bitmap, {rbound.first, rline}, {cline, cbound.second});
        decomp_dfs(bitmap, {rline, rbound.second}, {cbound.first, cline});
        decomp_dfs(bitmap, {rline, rbound.second}, {cline, cbound.second});
    }
    else {
        ans += to_string(val);
    }
}

void recon_dfs(vector<vector<int>>& bitmap, pair<int, int> rbound, pair<int, int> cbound) {
    if (rbound.first >= rbound.second || cbound.first >= cbound.second) return;
    char ch;
    cin >> ch;
    if (ch == 'D') {
        int rline = (rbound.first + rbound.second + 1) / 2;
        int cline = (cbound.first + cbound.second + 1) / 2;
        recon_dfs(bitmap, {rbound.first, rline}, {cbound.first, cline});
        recon_dfs(bitmap, {rbound.first, rline}, {cline, cbound.second});
        recon_dfs(bitmap, {rline, rbound.second}, {cbound.first, cline});
        recon_dfs(bitmap, {rline, rbound.second}, {cline, cbound.second});        
    }
    else {
        for (int r = rbound.first; r < rbound.second; ++r) {
            for (int c = cbound.first; c < cbound.second; ++c) {
                bitmap[r][c] = ch - '0';
            }
        }
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    char format;
    int rows, cols;
    while (true) {
        cin >> format;
        if (format == '#') break;
        cin >> rows >> cols;
        vector<vector<int>> bitmap(rows, vector<int>(cols, 0));
        if (!rows && !cols) goto print_label;
        if (format == 'B') {
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    char ch;
                    cin >> ch;
                    bitmap[r][c] = ch - '0';
                }
            }
            decomp_dfs(bitmap, {0, rows}, {0, cols}); 
        }
        else if (format == 'D') {
            recon_dfs(bitmap, {0, rows}, {0, cols});
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    ans += to_string(bitmap[r][c]);
                }
            }
        }
        print_label:
        cout << ((format == 'B') ? 'D' : 'B') 
             << right << setw(4) << rows
             << right << setw(4) << cols << '\n';
        for (int i = 0; i < ans.size(); ++i) {
            if (i > 0 && i % 50 == 0) {
                cout << '\n';
            }
            cout << ans[i];
        }
        cout << '\n';
        ans = "";
    }    

    return 0;
}