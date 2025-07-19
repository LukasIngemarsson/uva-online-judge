#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int N, M;
    while (true) {
        cin >> N >> M;
        if (!N && !M) break;
        vector<pair<int, int>> ab_nums(M, {0, 0}); // {P_i, K}
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < M; ++i) {
            int ab;
            cin >> ab;
            ab_nums[i].first = ab;
            pq.push({ab, i});
        }
        for (int i = 0; i < N; ++i) {
            pair<int, int> p = pq.top();
            pq.pop(); 
            int keeper_i = p.second;
            int safe_num = ab_nums[keeper_i].first;
            pq.push({safe_num / (++ab_nums[keeper_i].second + 1), keeper_i});
        }
        int L = INT_MAX;
        for (auto& p : ab_nums) {
            if (p.second == 0) continue;
            int U_j = p.first / p.second;
            L = min(L, U_j);
        }

        int Y = 0;
        if (L > 0) {
            vector<int> valid_ab_nums;
            for (int i = 0; i < M; ++i) {
                if (ab_nums[i].first >= L) {
                    valid_ab_nums.push_back(ab_nums[i].first);
                }
            }
            int new_M = valid_ab_nums.size();
            vector<vector<int>> state(new_M + 1, vector<int>(N + 1, INT_MAX));
            state[0][0] = 0;
            for (int i = 1; i <= new_M; ++i) {
                int alloc = valid_ab_nums[i-1] / L;
                for (int j = 0; j <= N; ++j) {
                    if (state[i-1][j] == INT_MAX) continue;
                    state[i][j] = min(state[i][j], state[i-1][j]);
                    int new_cap = min(N, j + alloc);
                    state[i][new_cap] = min(state[i][new_cap], state[i-1][j] + valid_ab_nums[i-1]);
                }
            }
            Y = state[new_M][N];
        }
        cout << L << " " << ((Y < INT_MAX) ? Y : 0) << '\n';
    }    

    return 0;
}