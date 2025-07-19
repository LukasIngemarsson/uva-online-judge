#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    for (int ti = 0; ti < t; ++ti) {
        int x, y;
        cin >> x >> y;
        set<pair<int, int>> in_path;
        char dir;
        while (true) {
            cin >> dir;
            if (dir == '.') break;
            switch (dir) {
                case 'E':
                    in_path.insert({x++, y-1});
                    break;
                case 'W':
                    in_path.insert({x--, y});
                    break;
                case 'N':
                    in_path.insert({x, y++});
                    break;
                case 'S':
                    in_path.insert({x-1, y--});
                    break;
            }
        }
        cout << "Bitmap #" << ti + 1 << '\n';
        for (int r = 32-1; r >= 0; --r) {
            for (int c = 0; c < 32; ++c) {
                cout << ((in_path.find({c, r}) != in_path.end()) ? 'X' : '.');
            }
            cout << '\n';
        }
        cout << '\n';
    }
 
    return 0;
}