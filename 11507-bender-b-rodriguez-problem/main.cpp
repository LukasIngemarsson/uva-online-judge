#include <bits/stdc++.h>

using namespace std;

vector<int> cross_product(vector<int> A, vector<int> B) {
    return {A[1] * B[2] - A[2] * B[1], 
            A[2] * B[0] - A[0] * B[2], 
            A[0] * B[1] - A[1] * B[0]};
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    int L;
    string dir;

    while (true) {
        cin >> L;
        if (!L) break;

        vector<int> end_dir = {1, 0, 0};
        vector<int> bend_dir, bend_axis, cross_prod_dir;

        for (int _ = 0; _ < L - 1; ++_) {
            cin >> dir;

            if (dir != "No") {
                if (dir[1] == 'y') {
                    bend_dir = {0, (dir[0] == '+') ? 1 : -1, 0};
                }
                else {
                    bend_dir = {0, 0, (dir[0] == '+') ? 1 : -1};
                }
                bend_axis = cross_product({1, 0, 0}, bend_dir);
                cross_prod_dir = cross_product(bend_axis, end_dir);

                if (cross_prod_dir[0] || cross_prod_dir[1] || cross_prod_dir[2]) {
                    end_dir = cross_prod_dir;
                }
            }
        }
        if (end_dir[0]) {
            cout << ((end_dir[0] > 0) ? '+' : '-') << "x\n";
        }
        else if (end_dir[1]) {
            cout << ((end_dir[1] > 0) ? '+' : '-') << "y\n";
        }
        else {
            cout << ((end_dir[2] > 0) ? '+' : '-') << "z\n";
        }
    }
    return 0;
}