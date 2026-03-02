#include <bits/stdc++.h>
using namespace std;

#define INF (int)2e9

struct Edge {
    int v, c, i;
    Edge (int v, int c, int i) : v(v), c(c), i(i) {}
};

struct Path {
    int u, c;
    vector<int> edge_idxs;
    Path (int u, int c, vector<int> edge_idxs) : u(u), c(c), edge_idxs(edge_idxs) {}
};

struct OptItem {
    int c;
    unordered_set<int> used_edges;
    OptItem (int c) : c(c) {}
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int V, E;
    while (cin >> V >> E) {
        vector<vector<Edge>> adj(V + 1);
        for (int i = 1; i <= E; ++i) {
            int s, t, c;
            cin >> s >> t >> c;
            adj[s].push_back(Edge(t, c, i));
            adj[t].push_back(Edge(s, c, i));
        }

        vector<int> edge_cnt(E + 1);
        for (int st = 1; st <= V; ++st) {
            vector<OptItem> opt(V + 1, OptItem(INF));
            queue<Path> q;
            q.push(Path(st, 0, {}));
            while (!q.empty()) {
                auto path = q.front(); q.pop();
                for (auto& e : adj[path.u]) {
                    if (path.c + e.c > opt[e.v].c)
                        continue;
                    Path new_path(path);
                    new_path.u = e.v;
                    new_path.c += e.c;
                    new_path.edge_idxs.push_back(e.i);
                    q.push(new_path);
                    if (new_path.c < opt[e.v].c) {
                        opt[e.v].c = new_path.c;
                        opt[e.v].used_edges.clear();
                    }
                    for (int i : new_path.edge_idxs)
                        opt[e.v].used_edges.insert(i);
                }
            }
            for (int i = st + 1; i < opt.size(); ++i)
                for (int idx : opt[i].used_edges)
                    ++edge_cnt[idx];
        }

        int max_used = 0;
        vector<int> max_used_edge_idxs;
        for (int i = 1; i <= E; ++i) {
            if (edge_cnt[i] >= max_used) {
                if (edge_cnt[i] > max_used) {
                    max_used = edge_cnt[i];
                    max_used_edge_idxs.clear();
                }
                max_used_edge_idxs.push_back(i);
            }
        }
        for (int i = 0; i < max_used_edge_idxs.size(); ++i) {
            if (i > 0)
                cout << ' ';
            cout << max_used_edge_idxs[i];
        }
        cout << '\n';
    }

    return 0;
}
