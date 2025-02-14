#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int N, t = 1;
    while (cin >> N) {
        vector<int> v(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }
        long long ans = 0;
        for (int i = 0; i < N; ++i) {
            long long prod = 1;
            for (int j = i; j < N; ++j) {
                prod *= v[j];
                ans = max(ans, prod);
            }
        }
        cout << "Case #" << t++ << ": The maximum product is " << ans << ".\n\n";
    }

    return 0;
}