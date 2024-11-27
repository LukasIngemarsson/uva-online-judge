#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    int n;

    while (true) {
        cin >> n;

        if (n == 0) break;

        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<vector<int>> state_opt(n, vector<int>(n, 0));

        for (int seq_len = 1; seq_len <= n; seq_len++) {
            for (int i = 0; i <= n - seq_len; i++) {
                int opt_diff = numeric_limits<int>::min();
                int acc_cost = 0, curr = 0;
                int seq_end_i = i + seq_len - 1;

                for (int j = 0; j < seq_len; j++) {
                    acc_cost += arr[i+j];
                    curr = (i + j + 1 <= seq_end_i) ? acc_cost - state_opt[i+j+1][seq_end_i] : acc_cost;

                    if (curr > opt_diff) opt_diff = curr;
                }
                acc_cost = 0;

                for (int j = 0; j < seq_len - 1; j++) {
                    acc_cost += arr[seq_end_i-j];
                    curr = (seq_end_i - j - 1 >= i) ? acc_cost - state_opt[i][seq_end_i-j-1] : acc_cost;

                    if (curr > opt_diff) opt_diff = curr;
                }
                state_opt[i][seq_end_i] = opt_diff;
            }
        }
        cout << state_opt[0][n-1] << '\n';
    }
    return 0;
}