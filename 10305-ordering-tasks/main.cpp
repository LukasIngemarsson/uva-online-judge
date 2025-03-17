#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m && (n || m)) {
        vector<vector<int>> v(n + 1);
        vector<int> in_deg(n + 1);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            ++in_deg[b];
        }
        
        vector<int> seq;
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (in_deg[i] == 0) {
                q.push(i);
                seq.push_back(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nbr : v[cur]) {
                if (--in_deg[nbr] == 0) {
                    q.push(nbr);
                    seq.push_back(nbr);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << ' ';
            cout << seq[i];
        }
        cout << '\n';
    }

    return 0;
}