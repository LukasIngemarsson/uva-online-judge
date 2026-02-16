#include <bits/stdc++.h>
using namespace std;

vector<int> get_dists(int st, int N, vector<vector<int>>& adj) {
    queue<pair<int, int>> q;
    q.push({st, 0});
    vector<int> dist(N, -1);
    dist[st] = 0;
    while (!q.empty()) {
        auto& [u, c] = q.front(); q.pop();
        for (auto& v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = c + 1;
                q.push({v, dist[v]});
            }
        }
    }
    return dist;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, R; cin >> N >> R;
        vector<vector<int>> adj(N);
        int u, v;
        for (int i = 0; i < R; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int s, d; cin >> s >> d;

        auto dist1 = get_dists(s, N, adj);
        auto dist2 = get_dists(d, N, adj);
        int ans = 0;
        for (int i = 0; i < N; ++i)
            ans = max(ans, dist1[i] + dist2[i]);
        cout << "Case " << t << ": " << ans << '\n';
    }

    return 0;
}
