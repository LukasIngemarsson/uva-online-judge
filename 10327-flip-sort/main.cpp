#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int N;
    while (cin >> N) {
        vector<int> v(N);
        for (int i = 0; i < N; ++i) cin >> v[i];

        vector<int> sorted(v);
        sort(sorted.begin(), sorted.end());
        int ans = 0;
        for (int i = N - 1; i >= 0; --i) {
            for (int j = i; j >= 0; --j) {
                if (v[j] == sorted[i]) {
                    ans += i - j;
                    v.erase(v.begin() + j);
                    break;
                }
            }
        }
        cout << "Minimum exchange operations : " << ans << '\n';
    }

    return 0;
}
