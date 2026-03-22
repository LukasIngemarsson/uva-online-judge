#include <bits/stdc++.h>
using namespace std;

#define BND 99
#define LIM 2 * BND + 1

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;
    bool filled[LIM][LIM];
    for (int t = 1; t <= T; ++t) {
        memset(filled, false, sizeof(filled));;
        int N;
        cin >> N;
        int ans = 0; 
        while (N--) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1 += BND, y1 += BND;
            x2 += BND, y2 += BND;

            bool valid = true;
            for (int x = x1; x < x2; ++x) {
                for (int y = y1; y < y2; ++y) {
                    if (filled[x][y]) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid)
                continue;
            for (int x = x1; x < x2; ++x)
                for (int y = y1; y < y2; ++y)
                    filled[x][y] = true;
            ans += (x2 - x1) * (y2 - y1);
        }
        cout << "Case " << t << ": " << ans << '\n';
    }

    return 0;
}
