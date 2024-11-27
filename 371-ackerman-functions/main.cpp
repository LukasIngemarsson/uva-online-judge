#include <iostream>
#include <string>
#include <utility>

#define long long long

using namespace std;

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    pair<long, long> bound;

    while (true) {
        cin >> bound.first >> bound.second;

        if (bound.first > bound.second) {
            swap(bound.first, bound.second);
        }
        if (bound.first == 0 && bound.second == 0) {
            break;
        }
        pair<long, long> longest = {-1, -1};

        for (long i = bound.first; i <= bound.second; i++) {
            long val = i, series_len = 0;

            do {
                if (val % 2 == 0) {
                    val /= 2;
                }
                else {
                    val = 3 * val + 1;
                }
                series_len++;
            } while (val != 1);

            if (series_len > longest.second) {
                longest.first = i;
                longest.second = series_len;
            }
        }
        cout << "Between " << bound.first << " and " << bound.second << ", " << longest.first << 
                " generates the longest sequence of " << longest.second << " values." << '\n';
    }
    return 0;
}