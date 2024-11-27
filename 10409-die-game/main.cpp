#include <bits/stdc++.h>
using namespace std;

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    map<char, char> side_to_opposing;
    pair<char ,char> opposites[3] = {{'n', 's'}, {'w', 'e'}, {'t', 'b'}};
    for (auto& p : opposites) {
        side_to_opposing[p.first] = p.second;
        side_to_opposing[p.second] = p.first;
    }
    int n;
    while (true) {
        cin >> n;
        if (!n) break;
        vector<char> sides = {'t', 'n', 'w'};
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            char dir_ = s[0];
            for (char& p : sides) {
                if (p == 't') p = dir_;
                else if (p == dir_) p = 'b';
                else if (p == 'b') p = side_to_opposing[dir_];
                else if (p == side_to_opposing[dir_]) p = 't';
            }
        }
        for (int i = 0; i < sides.size(); ++i) {
            if (sides[i] == 't') {
                cout << i + 1 << '\n';
                break;
            }
            else if (sides[i] == 'b') {
                cout << 6 - i << '\n';
                break;
            }
        }
    } 

    return 0;
}