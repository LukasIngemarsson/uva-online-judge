#include <bits/stdc++.h>
using namespace std;

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    int n, m, c, t = 1;
    while (true) {
        cin >> n >> m >> c;
        if (!n && !m && !c) break;
        vector<int> cons(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> cons[i];
        }
        vector<bool> state(n, false);
        int sum = 0, max_sum = 0;
        for (int _ = 0; _ < m; ++_) {
            int j;
            cin >> j;
            state[j-1] = !state[j-1];
            if (state[j-1]) sum += cons[j-1];
            else sum -= cons[j-1];
            if (sum > max_sum) max_sum = sum;
        } 
        cout << "Sequence " << t++ << '\n';
        if (max_sum > c) {
            cout << "Fuse was blown.\n\n";
        }
        else {
            cout << "Fuse was not blown.\nMaximal power consumption was " << max_sum << " amperes.\n\n";
        }
    }

    return 0;
}