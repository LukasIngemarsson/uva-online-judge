#include <bits/stdc++.h>
using namespace std;

vector<int> mem(1e7 + 1, -1);

int f91(int N) {
    if (mem[N] != -1)
        return mem[N];
    mem[N] = (N <= 100) ? f91(f91(N + 11)) : N - 10;
    return mem[N];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int N;
    while (cin >> N and N != 0) {
        cout << "f91(" << N << ") = " << f91(N) << '\n';
    }

    return 0;
}
