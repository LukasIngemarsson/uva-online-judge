#include <bits/stdc++.h>
using namespace std;

double c_to_f(double C) {
    return (9.0 / 5.0) * C + 32;
} 
double f_to_c(double F) {
    return 5 * (F - 32) / 9;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    for (int ti = 0; ti < t; ++ti) {
        double start, change;
        cin >> start >> change;
        double res = f_to_c(c_to_f(start) + change);
        cout << "Case " << (ti + 1) << ": " << fixed << setprecision(2) << res << '\n';
    }
    return 0;
}