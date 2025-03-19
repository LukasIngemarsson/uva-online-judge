#include <bits/stdc++.h>
using namespace std;

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    vector<int> die_throws;
    int a, b;
    while (true) {
        cin >> a;
        if (!a) break;
        die_throws.push_back(a);
    } 
    while (true) {
        int num_players;
        cin >> num_players;
        if (!num_players) break;
        map<int, int> chutes_and_ladders;
        while (true) {
            cin >> a >> b;
            if (!a && !b) break;
            chutes_and_ladders.insert({a, b});
        }
        set<int> lose_and_extra_turns;
        while (true) {
            cin >> a;
            if (!a) break;
            lose_and_extra_turns.insert(a);
        }
        int curr = 1;
        vector<pair<int, bool>> player_pos(num_players + 1, {0, false});
        auto update_curr = [&] () {
            curr = (curr + 1 <= num_players) ? curr + 1 : 1; 
            while (player_pos[curr].second) {
                player_pos[curr].second = false;
                curr = (curr + 1 <= num_players) ? curr + 1 : 1; 
            }
        };
        for (int th : die_throws) {
            pair<int, bool>* p = &player_pos[curr];
            if (p->first + th > 100) {
                update_curr();
                continue;
            }
            p->first += th;
            if (p->first == 100) {
                cout << curr << '\n';
                break;
            }     
            if (chutes_and_ladders.find(p->first) != chutes_and_ladders.end()) {
                p->first = chutes_and_ladders[p->first];
            }       
            if (lose_and_extra_turns.find(-p->first) != lose_and_extra_turns.end()) {
                p->second = true;
            }
            if (lose_and_extra_turns.find(p->first) == lose_and_extra_turns.end()) {
                update_curr();
            }
        }
    }

    return 0;
}