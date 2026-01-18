#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define INF (int)1e9 

struct Edge {
    int u, v, f;

    Edge(int u, int v, int f) : u(u), v(v), f(f) {}
};

struct Graph {
    int n;
    vvi adj; 
    vvi cap; // residual capacity of each edge
    set<pii> edges; // used to prevent adding duplicates to the adjacency list

    Graph(int n) : n(n), adj(n), cap(n, vi(n)) {}

    void add_edge(int u, int v, int c) {
        // pairs of nodes with multiple edges between each other
        // are simply represented by a single edge with their joint capacity
        pii e = {min(u, v), max(u, v)};
        if (edges.find(e) == edges.end()) {
            adj[u].push_back(v);
            adj[v].push_back(u); // add reverse edge to allow flow backwards
            cap[v][u] = 0; // set reverse edge capacity to zero
            edges.insert(e);
        }
        cap[u][v] += c;
    }
};

int bfs(Graph& G, int s, int t, vi& par) {
    fill(par.begin(), par.end(), -1);

    queue<pii> q;
    q.push({s, INF});
    par[s] = -2; // source has no parent
    while(!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int nxt : G.adj[cur]) {
            if (par[nxt] == -1 && G.cap[cur][nxt]) {
                par[nxt] = cur;
                int new_flow = min(flow, G.cap[cur][nxt]);
                if (nxt == t) {
                    return new_flow;
                }
                q.push({nxt, new_flow});
            }
        }
    }
    return 0;
}

pair<int, vector<Edge>> edmonds_karp(Graph& G, int s, int t) {
    int n = G.n;
    vi par(n); // parent of each node in the path
    vvi flows(n, vi(n)); // flow of each edge

    int tot_flow = 0;
    while (int new_flow = bfs(G, s, t, par)) {
        tot_flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = par[cur];
            // adjust residual capacity of edges in path
            G.cap[prev][cur] -= new_flow;
            G.cap[cur][prev] += new_flow;
            // update flow
            flows[prev][cur] += new_flow;
            flows[cur][prev] -= new_flow;
            cur = prev;
        }
    }

    vector<Edge> used_edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (flows[i][j] > 0) {
                used_edges.push_back(Edge(i, j, flows[i][j]));
            }
        }
    }

    return {tot_flow, used_edges};
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int N;
    while (cin >> N) {
        Graph G(2 * N + 2 + 1);
        int SRC = 2 * N + 1, SINK = 2 * N + 2;

        int c;
        for (int i = 1; i <= N; ++i) {
            cin >> c;
            G.add_edge(N + i, i, c);
        }

        int M;
        cin >> M;
        int u, v, f;
        for (int i = 0; i < M; ++i) {
            cin >> u >> v >> f; 
            G.add_edge(u, v + N, f);
        }

        int B, D;
        cin >> B >> D;
        for (int i = 0; i < B; ++i) {
            cin >> u;
            G.add_edge(SRC, N + u, INF);
        }
        for (int i = 0; i < D; ++i) {
            cin >> u;
            G.add_edge(u, SINK, INF);
        }

        auto [max_flow, _] = edmonds_karp(G, SRC, SINK);
        cout << max_flow << '\n';
    }

    return 0;
}
