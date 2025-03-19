#include <bits/stdc++.h>
using namespace std;

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    int n;
    while (true) {
        cin >> n;
        if (!n) break;
        int num_sheets = ceil(n / 4.0);
        cout << "Printing order for " << n << " pages:\n";
        for (int i = 0; i < num_sheets; ++i) {
            int a = num_sheets * 4 - 2 * i;
            int b = (i * 2) + 1;
            string fl = (a <= n) ? to_string(a) : "Blank";
            string fr = to_string(b);
            cout << "Sheet " << i + 1 << ", front: " << fl << ", " << fr << '\n';
            string bl = (b + 1 <= n) ? to_string(b + 1) : "Blank";
            string br = (a - 1 <= n) ? to_string(a - 1) : "Blank";
            if (bl == "Blank" && br == "Blank") break;
            cout << "Sheet " << i + 1 << ", back : " << bl << ", " << br << '\n';
        }
    }    

    return 0;
}