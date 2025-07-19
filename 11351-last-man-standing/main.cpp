#include <iostream>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int num_cases;
    cin >> num_cases;

    for (int c = 0; c < num_cases; c++) {
        int n, k;
        cin >> n >> k;

        // init to 0, as a round w/ one participant will be the survivor
        int survivor_i = 0;

        for (int circle_size = 2; circle_size <= n; circle_size++) {
            survivor_i = (survivor_i + k) % circle_size;
        }
        cout << "Case " << c + 1 << ": " << survivor_i + 1 << '\n';
    }
    return 0;
}