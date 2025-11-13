#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    set<long long> s;
    s.insert(1); 
    long long curr = 1;

    for (int i = 0; i < 1500; ++i) {
        curr = *s.begin();
        s.erase(s.begin());
        s.insert({curr * 2, curr * 3, curr * 5});
    }
    cout << "The 1500'th ugly number is " << curr << ".\n";

    return 0;
}
