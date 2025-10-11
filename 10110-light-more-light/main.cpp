#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    long long n; 
    while (cin >> n && n != 0) {
        long long sqrt_n = sqrt(n);
        bool is_perfect_square = sqrt_n * sqrt_n == n;
        cout << (is_perfect_square ? "yes" : "no") << '\n';
    }

    return 0;
}
