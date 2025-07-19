#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    auto custom_sort = [](const tuple<int, int, string> &a, const tuple<int, int, string> &b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
        if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
        return get<2>(a) < get<2>(b);
    };
    int t, player_num = 10;
    cin >> t;
    for (int ti = 1; ti < t + 1; ++ti) {
        vector<tuple<int, int, string>> players(player_num);
        for (int i = 0; i < player_num; ++i) {
            string name;
            int att, def;
            cin >> name >> att >> def;
            players[i] = make_tuple(att, def, name);
        }
        sort(players.begin(), players.end(), custom_sort);
        int half = player_num / 2;
        vector<string> attackers(half);
        vector<string> defenders(half);
        for (int i = 0; i < half; ++i) {
            attackers[i] = get<2>(players[i]);
            defenders[i] = get<2>(players[i+half]);
        }
        sort(attackers.begin(), attackers.end());
        cout << "Case " << ti << ":\n(";
        for (int i = 0; i < half; ++i) {
            if (i > 0) cout << ", ";
            cout << attackers[i];
        }
        cout << ")\n";
        sort(defenders.begin(), defenders.end());
        cout << '(';
        for (int i = 0; i < half; ++i) {
            if (i > 0) cout << ", ";
            cout << defenders[i];
        }
        cout << ")\n";
    }

    return 0;
}