#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class BipartiteMatcher {
public:
    int V;
    vector<vector<int>> adj;
    vector<int> pair_U, pair_V, dist;

    BipartiteMatcher(int V) : V(V), adj(V), pair_U(V, -1), pair_V(V, -1), dist(V, -1) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int> queue;

        for (int u = 0; u < V; u++) {
            if (pair_U[u] == -1) {
                dist[u] = 0;
                queue.push(u);
            } 
            else {
                dist[u] = -1;
            }
        }
        bool found_augmenting_path = false;

        while (!queue.empty()) {
            int u = queue.front();
            queue.pop();

            for (int v : adj[u]) {
                if (pair_V[v] == -1) {
                    found_augmenting_path = true;
                } 
                else if (dist[pair_V[v]] == -1) {
                    dist[pair_V[v]] = dist[u] + 1;
                    queue.push(pair_V[v]);
                }
            }
        }
        return found_augmenting_path;
    }

    bool dfs(int u) {
        for (int v : adj[u]) {
            if (pair_V[v] == -1 || (dist[pair_V[v]] == dist[u] + 1 && dfs(pair_V[v]))) {
                pair_U[u] = v;
                pair_V[v] = u;
                return true;
            }
        }
        dist[u] = -1;
        return false;
    }

    int hopcroft_karp() {
        int matching = 0;

        while (bfs()) {
            for (int u = 0; u < V; u++) {
                if (pair_U[u] == -1 && dfs(u)) {
                    matching++;
                }
            }
        }
        return matching;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int N;

    while (cin >> N) {
        vector<vector<bool>> grid(N, vector<bool>(N));
        char ch;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                cin >> ch;
                grid[r][c] = (ch == 'X') ? true : false;
            }
        }
        int rseg_count = 0, cseg_count = 0;
        vector<vector<int>> row_seg(N, vector<int>(N, -1));
        vector<vector<int>> col_seg(N, vector<int>(N, -1));

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (grid[r][c]) continue;
                
                if (c == 0 || grid[r][c - 1]) {
                    rseg_count++;
                }
                row_seg[r][c] = rseg_count - 1;
            }
        }
        for (int c = 0; c < N; c++) {
            for (int r = 0; r < N; r++) {
                if (grid[r][c]) continue;

                if (r == 0 || grid[r - 1][c]) {
                    cseg_count++;
                }
                col_seg[r][c] = cseg_count - 1;
            }
        }
        BipartiteMatcher bm(max(rseg_count, cseg_count));

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (!grid[r][c]) {
                    bm.add_edge(row_seg[r][c], col_seg[r][c]);
                }
            }
        }
        cout << bm.hopcroft_karp() << '\n';
    }
    return 0;
}