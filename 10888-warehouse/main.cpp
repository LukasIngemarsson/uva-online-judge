#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

// hungarian algorithm from KACTL
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int ll
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

pair<int, vi> hungarian(const vector<vi> &a) {
	if (a.empty()) return {0, {}};
	int n = sz(a) + 1, m = sz(a[0]) + 1;
	vi u(n), v(m), p(m), ans(n - 1);
	rep(i,1,n) {
		p[0] = i;
		int j0 = 0; // add "dummy" worker 0
		vi dist(m, INT_MAX), pre(m, -1);
		vector<bool> done(m + 1);
		do { // dijkstra
			done[j0] = true;
			int i0 = p[j0], j1, delta = INT_MAX;
			rep(j,1,m) if (!done[j]) {
				auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
				if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
				if (dist[j] < delta) delta = dist[j], j1 = j;
			}
			rep(j,0,m) {
				if (done[j]) u[p[j]] += delta, v[j] -= delta;
				else dist[j] -= delta;
			}
			j0 = j1;
		} while (p[j0]);
		while (j0) { // update alternating path
			int j1 = pre[j0];
			p[j0] = p[j1], j0 = j1;
		}
	}
	rep(j,1,m) if (p[j]) ans[p[j] - 1] = j - 1;
	return {-v[0], ans}; // min cost
}

pair<int, int> coord_off[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        int h, w;
        cin >> h >> w;

        vector<vector<char>> grid(h, vector<char>(w));
        vector<pair<int, int>> starts;
        vector<pair<int, int>> ends;

        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                cin >> grid[r][c];

                if (grid[r][c] == 'B') {
                    starts.push_back({r, c});
                }
                else if (grid[r][c] == 'X') {
                    ends.push_back({r, c});
                }
            }
        }
        vector<vector<int>> dists;

        for (auto &start : starts) {
            queue<pair<int, int>> q;
            vector<vector<bool>> vis(h, vector<bool>(w, false));
            vector<vector<int>> dis(h, vector<int>(w, (int)1e13));
            int sr = start.first, sc = start.second;

            q.push({sr, sc});
            vis[sr][sc] = true;
            dis[sr][sc] = 0;

            while (!q.empty()) {
                pair<int, int> curr = q.front(); 
                q.pop();
                int r = curr.first, c = curr.second;

                for (pair<int, int> off : coord_off) {
                    int adjr = r + off.first, adjc = c + off.second;

                    if (adjr >= 0 && adjr < h && adjc >= 0 &&
                         adjc < w && !vis[adjr][adjc] && grid[adjr][adjc] != '#') {
                        q.push({adjr, adjc});
                        vis[adjr][adjc] = true;
                        dis[adjr][adjc] = dis[r][c] + 1;
                    }
                }
            }
            vector<int> end_dis;

            for (auto &end: ends) {
                end_dis.push_back(dis[end.first][end.second]);
            }
            dists.push_back(end_dis);
        }
        pair<int, vector<int>> res = hungarian(dists);
        int min_cost = res.first;
        vector<int> opt = res.second;
        cout << min_cost << '\n';
    }

    return 0;
}