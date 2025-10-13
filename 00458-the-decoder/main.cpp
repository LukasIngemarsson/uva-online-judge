#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    string s;
    while (getline(cin, s)) {
        for (char& ch : s) {
            cout << char(int(ch) - 7); 
        }
        cout << '\n';
    }

    return 0;
}
