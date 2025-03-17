#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int D = 1000000;
    int x[D + 1];
    x[0] = 1;
    for (int i = 1; i <= D; ++i) {
        int i1 = floor(i - sqrt(i));
        int i2 = floor(log(i));
        int i3 = floor(i * pow(sin(i), 2));
        x[i] = (x[i1] + x[i2] + x[i3]) % D;
    }

    int n;
    while (cin >> n && n != -1) {
        cout << x[n] << '\n';
    }

    return 0;
}