#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define tiii tuple<int, int, int>

vector<pii> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs_from_shop(int start_r, int start_c, int dx, int dy, int m, map<pii, int>& reachable_count) {
    queue<tiii> q;
    set<pii> visited;
    q.push({start_r, start_c, 0});
    visited.insert({start_r, start_c});

    while (!q.empty()) {
        int r, c, d;
        tie(r, c, d) = q.front();
        q.pop();
        ++reachable_count[{r, c}];

        if (d >= m) continue;

        for (const auto& dir : dirs) {
            int newr = r + dir.first, newc = c + dir.second;
            if (1 <= newr && newr <= dy && 1 <= newc && newc <= dx &&
                visited.find({newr, newc}) == visited.end()) {
                q.push({newr, newc, d + 1});
                visited.insert({newr, newc});
            }
        }
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    int case_num = 1;
    while (true) {
        int dx, dy, n, q;
        cin >> dx >> dy >> n >> q;
        if (!dx && !dy && !n && !q) break;
        vector<pii> shops(n);
        for (int i = 0; i < n; ++i) {
            cin >> shops[i].first >> shops[i].second;
        }
        cout << "Case " << case_num++ << ":\n";
        for (int i = 0; i < q; ++i) {
            int m;
            cin >> m;
            map<pii, int> reachable_count;

            for (pii sh : shops) {
                bfs_from_shop(sh.first, sh.second, dx, dy, m, reachable_count);
            }
            pair<pii, int> opt = {{dy + 1, dx + 1}, 0};
            for (auto &kvp : reachable_count) {
                int r = kvp.first.first, c = kvp.first.second;
                cout << r << " " << c << " " << kvp.second << '\n';
                if (kvp.second > opt.second || (kvp.second == opt.second &&
                     make_pair(r, c) < opt.first)) {
                    opt = {{r, c}, kvp.second};
                }
            }
            cout << opt.second << " (" << opt.first.first << "," << opt.first.second << ")\n";
        }
    }
    return 0;
}
