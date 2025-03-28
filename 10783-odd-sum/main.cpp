#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int a, b; cin >> a >> b;
        int s = 0;
        for (int i = a; i <= b; ++i) {
            if (i % 2 != 0) s += i;
        }
        cout << "Case " << t << ": " << s << '\n';
    }

    return 0;
}
