#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;

void dfs(int st, vector<vector<int>>& adj, vector<int>& output) {
    visited[st] = true;
    for (auto u : adj[st]) {
        if (!visited[u]) {
            dfs(u, adj, output);
        }
    }
    output.push_back(st);
}

/*
@brief Identifies the Strongly Connected Components (SCCs) in the graph, 
and creates the corresponding condensation graph.

A subset of nodes `C` is called an SCC if 
    1. for all `u`, `v` in `C` (`u` != `v`) there exists a path from `u` to `v` and from `v` to `u`, and
    2. `C` is maximal, i.e., no node can be added without violating the above condition.

@return A pair containing 1. the SCCs, and 2. the adjacency list of the condensation graph.

@note Time complexity: `O(n + m)`, where `n` is the number of nodes and `m` is the number of edges.
*/
pair<vector<vector<int>>, vector<vector<int>>> scc(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> order; 

    visited.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, order);
        }
    }

    // create the graph's transposed adjacency list
    vector<vector<int>> rev_adj(n);
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            rev_adj[v].push_back(u);
        }
    }

    visited.assign(n, false);
    reverse(order.begin(), order.end());

    vector<vector<int>> components;
    vector<int> roots(n, 0); // stores the root node of a node's SCC
    for (auto u : order) {
        if (!visited[u]) {
            vector<int> comp;
            dfs(u, rev_adj, comp);
            components.push_back(comp);
            int root = *min_element(comp.begin(), comp.end());
            for (auto v : comp) {
                roots[v] = root;
            }
        }
    }

    // create condensation adjacency list
    vector<vector<int>> cond_adj(n);
    for (int u = 0; u < n; ++u) {
        for (auto v : adj[u]) {
            if (roots[u] != roots[v]) {
                cond_adj[roots[u]].push_back(roots[v]);
            }
        }
    }

    return {components, cond_adj};
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; 
    cin >> t;

    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < M; ++i) {
            int A, B; 
            cin >> A >> B;
            adj[A].push_back(B);
            adj[B].push_back(A);
        }

        auto [comps, _] = scc(adj);

        int ans = 0;
        for (auto& c: comps)
            ans = max(ans, (int)c.size());

        cout << ans << '\n';

    }

    return 0;
}
