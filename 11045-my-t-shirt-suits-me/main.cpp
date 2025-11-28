#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9 

struct Edge {
    int u, v;
    int cap, flow = 0;
    Edge(int u, int v, int cap) : u(u), v(v), cap(cap) {}
};

/*
@brief Dinic's algorithm. 
Initialize with the number of nodes `n`, the source node `s`, and the sink node `t`.
Populate the graph using `add_edge()`.
*/
struct Dinic {
    int n, s, t;
    vector<Edge> edges;
    vector<vector<int>> adj; // stores ID's of edges from each node
    vector<int> level; // stores the level of each node in the level graph
    vector<int> ptr; // used to keep track of progress (already traversed edges) between DFS runs
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t), adj(n), level(n), ptr(n) {}

    void add_edge(int u, int v, int cap) {
        // the two edges are assigned ID's edges.size() and edges.size() + 1, respectively,
        // which corresponds to their indices in `edges`
        adj[u].push_back(edges.size());
        adj[v].push_back(edges.size() + 1);
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
    }

    bool bfs() {
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int id : adj[u]) {
                // skip the edge if it has consumed its full capacity,
                // or if the reachable node has already been marked in the level graph
                if (edges[id].cap == edges[id].flow || level[edges[id].v] != -1) {
                    continue;
                }
                level[edges[id].v] = level[u] + 1;
                q.push(edges[id].v);
            }
        }
        return level[t] != -1;
    }

    int dfs(int u, int pushed) {
        if (pushed == 0) { // dead end, cannot push flow further
            return 0;
        }
        if (u == t) { // sink reached
            return pushed;
        }
        // we use a reference of the ptr for the node `u`, so that the 
        // we pick up where we left off in subsequent DFS runs
        for (int& cur_idx = ptr[u]; cur_idx < adj[u].size(); ++cur_idx) {
            int id = adj[u][cur_idx];
            int v = edges[id].v;
            // only take steps that lead to the next level
            if (level[u] + 1 != level[v]) {
                continue;
            }
            // push as much flow as possible to next node `v`
            int flow = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
            if (flow == 0) { // dead end, cannot push flow further
                continue;
            }
            edges[id].flow += flow;
            edges[id ^ 1].flow -= flow; // id ^ 1 XOR gives opposite edge of regular/reverse
            return flow;
        }
        return 0;
    }

    /*
    @brief Finds the maximum flow from the source node to the sink node using Dinic's algorithm.

    @return The maximum flow.

    @note Time complexity: `O(n ^ 2 * m)`, where `n` is the number of nodes and `m`
    is the number of edges. For unit networks, this algorithm works in `O(sqrt(n) * m)`.
    */
    int max_flow() {
        int tot_flow = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);

            // stop if the sink cannot be reached in the level graph
            if (!bfs()) {
                break;
            }

            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, INF)) {
                tot_flow += pushed;
            }
        }
        return tot_flow;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int NUM_TSHIRTS = 6;
    vector<string> sizes = {"XS", "S", "M", "L", "XL", "XXL"};

    int tt; 
    cin >> tt;

    while (tt--) {
        int N, M;
        cin >> N >> M;

        int node_cnt = 0;
        int s = node_cnt++;
        int t = node_cnt++;

        int num_nodes = 2 + M + NUM_TSHIRTS;
        Dinic dinic(num_nodes, s, t);

        for (int i = 0; i < M; ++i)
            dinic.add_edge(s, node_cnt++, 1);

        unordered_map<string, int> size_to_id;
        int tshirts_per_size = N / NUM_TSHIRTS;
        for (auto& sz: sizes) {
            size_to_id[sz] = node_cnt;
            dinic.add_edge(node_cnt++, t, tshirts_per_size);
        }

        for (int i = 0; i < M; ++i) {
            string sz1, sz2;
            cin >> sz1 >> sz2;
            dinic.add_edge(2 + i, size_to_id[sz1], 1);
            dinic.add_edge(2 + i, size_to_id[sz2], 1);
        }

        int f = dinic.max_flow();
        cout << ((f == M) ? "YES" : "NO") << '\n';
    }

    return 0;
}
