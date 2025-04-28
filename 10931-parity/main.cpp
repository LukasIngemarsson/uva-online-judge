#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int I;
    while (cin >> I and I != 0) {
        string bit_rep = "";
        int s = 0;
        while (I > 0) {
            if (I % 2 == 1) {
                bit_rep += '1';
                ++s;
            }
            else {
                bit_rep += '0';
            }
            I /= 2;
        }
        reverse(bit_rep.begin(), bit_rep.end());
        cout << "The parity of " << bit_rep << " is " << s << " (mod 2).\n";
    }

    return 0;
}
