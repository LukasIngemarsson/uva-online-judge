#include <bits/stdc++.h>
using namespace std;

int knapsack(int capacity, vector<int>& items) {
    int n = items.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(capacity + 1));
    dp[0][0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int maxw = 0; maxw <= capacity; ++maxw) {
            int w = items[i-1];
            if (w <= maxw)
                dp[i][maxw] = dp[i-1][maxw] || dp[i-1][maxw - w];
            else
                dp[i][maxw] = dp[i-1][maxw];
        }
    }

    int ok_maxw = 0;
    for (int maxw = capacity; maxw >= 0; --maxw) {
        if (dp.back()[maxw]) {
            ok_maxw = maxw;
            break;
        }
    }

    return ok_maxw;
}


int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        vector<int> coins(m);
        int tot = 0;
        for (int j = 0; j < m; ++j) {
            cin >> coins[j];
            tot += coins[j];
        }
        int closest_to_half = knapsack(tot / 2, coins);
        int ans = tot - 2 * closest_to_half;
        cout << ans << '\n';
    }

    return 0;
}
