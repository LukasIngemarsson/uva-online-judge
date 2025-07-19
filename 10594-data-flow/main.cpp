#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>
#include <algorithm>

using namespace std;

const long long int INF = numeric_limits<long long int>::max();

struct Edge {
    int from, to;
    long long int capacity, cost, flow;
};

class MinCostMaxFlow {
public:
    int n;
    vector<vector<int>> adj;
    vector<Edge> edges;
    vector<long long int> dist, parent;
    vector<bool> in_queue;

    MinCostMaxFlow(int n) : n(n), adj(n), dist(n), parent(n), in_queue(n) {}

    void add_edge(int from, int to, long long int capacity, long long int cost) {
        edges.push_back({from, to, capacity, cost, 0});
        edges.push_back({to, from, 0, -cost, 0}); // reverse edge, to send flow backwards
        adj[from].push_back(edges.size() - 2);
        adj[to].push_back(edges.size() - 1);
    }

    bool spfa(int s, int t) {
        fill(dist.begin(), dist.end(), INF);
        fill(in_queue.begin(), in_queue.end(), false);
        queue<int> q;

        dist[s] = 0;
        in_queue[s] = true;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue[u] = false;

            for (int id : adj[u]) {
                Edge &e = edges[id];
                if (e.flow < e.capacity && dist[u] + e.cost < dist[e.to]) {
                    dist[e.to] = dist[u] + e.cost;
                    parent[e.to] = id;
                    if (!in_queue[e.to]) {
                        in_queue[e.to] = true;
                        q.push(e.to);
                    }
                }
            }
        }
        return dist[t] != INF;
    }

    pair<long long int, long long int> min_cost_max_flow(int s, int t) {
        long long int flow = 0, cost = 0;

        while (spfa(s, t)) {
            long long int curr_flow = INF;

            for (int v = t; v != s; v = edges[parent[v]].from) {
                curr_flow = min(curr_flow, edges[parent[v]].capacity - edges[parent[v]].flow);
            }

            for (int v = t; v != s; v = edges[parent[v]].from) {
                edges[parent[v]].flow += curr_flow;
                edges[parent[v] ^ 1].flow -= curr_flow;
                cost += curr_flow * edges[parent[v]].cost;
            }
            flow += curr_flow;
        }
        return {flow, cost};
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int N, M;

    while (cin >> N >> M) {
        MinCostMaxFlow mcmf(N + 1); // + 1 to make space for intermediate node
        mcmf.add_edge(0, N, -1, 0); // add intermediate node

        for (int i = 0; i < M; i++) {
            int n1, n2, temp;
            long long int c;
            cin >> n1 >> n2 >> c;
            n1--;
            n2--;

            if (n1 > n2) {
                temp = n1;
                n1 = n2;
                n2 = temp;
            }

            if (n1 == 0) { // redirect src node's adj nodes to intermediate node
                mcmf.add_edge(N, n2, -1, c);
                mcmf.add_edge(n2, N, -1, c);
            }
            else {
                mcmf.add_edge(n1, n2, -1, c);
                mcmf.add_edge(n2, n1, -1, c);
            }
        }
        long long int D, K;
        cin >> D >> K;

        for (int i = 0; i < mcmf.edges.size(); i++) {
            Edge &edge = mcmf.edges[i];

            if (edge.capacity != -1) { // leave reverse edges unchanged
                continue;
            }
            else if (edge.from == 0 && edge.to == N) {
                edge.capacity = D;
            }
            else {
                edge.capacity = K; 
            }
        }
        pair<long long int, long long int> result = mcmf.min_cost_max_flow(0, N - 1);

        if (result.first == D) {
            cout << result.second << '\n';
        }
        else {
            cout << "Impossible." << '\n';
        }
    }
    return 0;
}