#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define tiii tuple<int, int, int>

vector<pii> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int str, int stc, int dx, int dy, int m, set<pii> &shops) {
    queue<tiii> q;
    set<pii> visited;
    q.push({str, stc, 0});
    visited.insert({str, stc});
    int shop_count = 0;

    while (!q.empty()) {
        tiii curr = q.front(); 
        q.pop();
        int r, c, d;
        tie(r, c, d) = curr;

        if (shops.find({r, c}) != shops.end()) ++shop_count;
        if (d >= m) continue;

        for (pii dir : dirs) {
            int newr = r + dir.first, newc = c + dir.second;
            if (1 <= newr && newr <= dy && 1 <= newc && newc <= dx &&
                visited.find({newr, newc}) == visited.end()) {
                q.push({newr, newc, d + 1});
                visited.insert({newr, newc});
            }
        }
    }
    return shop_count;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    int case_num = 1;
    while (true) {
        int dx, dy, n, q;
        cin >> dx >> dy >> n >> q;
        if (!dx && !dy && !n && !q) break;

        set<pii> shops;
        for (int i = 0; i < n; ++i) {
            pii sh;
            cin >> sh.first >> sh.second;
            shops.insert(sh);
        }
        cout << "Case " << case_num << ":\n";
        for (int i = 0; i < q; ++i) {
            int m;
            cin >> m;
            pair<pii, int> opt = {{dy + 1, dx + 1}, 0};
            for (int r = 1; r <= dy; ++r) {
                for (int c = 1; c <= dx; ++c) {
                    int shops_num = bfs(r, c, dx, dy, m, shops);
                    cout << r << " " << c << " " << shops_num << '\n';
                    if (shops_num > opt.second || shops_num == opt.second &&
                        make_pair(r, c) < opt.first) {
                        opt = {{r, c}, shops_num};
                    }
                }
            }
            cout << opt.second << " " << "(" << opt.first.first << "," << opt.first.second << ")\n";
        }
        ++case_num;
    }
    return 0;
}