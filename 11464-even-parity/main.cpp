#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <limits>

using namespace std;

class MinTransformationSearcher {
public:
    int N = 0;
    int changes_count = 0;
    int min_sol = 0;
    int uneven_count = 0;
    vector<vector<int>> binary_grid;
    vector<vector<int>> parity_grid;

    MinTransformationSearcher(int N) : N(N) {
        min_sol = numeric_limits<int>::max();
        binary_grid = vector<vector<int>>(N, vector<int>(N));
        parity_grid = vector<vector<int>>(N, vector<int>(N));

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                cin >> binary_grid[r][c];
            }
        }
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (c > 0 && binary_grid[r][c-1] == 1) {
                    parity_grid[r][c]++;
                }
                if (c < N - 1 && binary_grid[r][c+1] == 1) {
                    parity_grid[r][c]++;
                }
                if (r > 0 && binary_grid[r-1][c] == 1) {
                    parity_grid[r][c]++;
                }
                if (r < N - 1 && binary_grid[r+1][c] == 1) {
                    parity_grid[r][c]++;
                }

                if (parity_grid[r][c] % 2 != 0) {
                    uneven_count++;
                }
            }
        }
    }

    void update_parities(int r, int c, bool inc) {
        int update_val = (inc) ? 1 : -1;

        if (r > 0) {
            parity_grid[r-1][c] += update_val;

            if (parity_grid[r-1][c] % 2 == 0) {
                uneven_count--;
            }
            else {
                uneven_count++;
            }
        }
        if (r < N - 1) {
            parity_grid[r+1][c] += update_val;

            if (parity_grid[r+1][c] % 2 == 0) {
                uneven_count--;
            }
            else {
                uneven_count++;
            }
        }
        if (c > 0) {
            parity_grid[r][c-1]+= update_val;

            if (parity_grid[r][c-1] % 2 == 0) {
                uneven_count--;
            }
            else {
                uneven_count++;
            }
        }
        if (c < N - 1) {
            parity_grid[r][c+1] += update_val;

            if (parity_grid[r][c+1] % 2 == 0) {
                uneven_count--;
            }
            else {
                uneven_count++;
            }
        }
    }

    bool is_valid_state(int r, int c) {
        if (r > 0 && parity_grid[r-1][c] % 2 != 0) {
            return false;
        }
        if ((r < N - 1 && parity_grid[r+1][c] % 2 != 0) &&
            !((c > 0 && binary_grid[r+1][c-1] == 0) ||
            (c < N - 1 && binary_grid[r+1][c+1] == 0) ||
            (r + 1 < N - 1 && binary_grid[r+2][c] == 0))) {
            return false;
        }
        if ((c > 0 && parity_grid[r][c-1] % 2 != 0) &&
            !(r < N - 1 && binary_grid[r+1][c-1] == 0)) {
            return false;
        }
        if ((c < N - 1 && parity_grid[r][c+1] % 2 != 0) &&
            !((c + 1 < N - 1 && binary_grid[r][c+2] == 0) ||
            (r < N - 1 && binary_grid[r+1][c+1] == 0))) {
            return false;
        }
        return true;
    }

    void print_grid(vector<vector<int>> grid) {
        for (auto& vect: grid) {
            for (auto& val: vect) {
                cout << val << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }

    void search(int r, int c) {
        if (uneven_count == 0) {
            if (changes_count < min_sol) {
                min_sol = changes_count;
            }
            return;
        }
        if (r >= N) {
            return;
        }
        if (binary_grid[r][c] == 0) {
            binary_grid[r][c] = 1;
            changes_count++;
            update_parities(r, c, true);

            if (is_valid_state(r, c)) {
                if (c < N - 1) {
                    search(r, c + 1);
                }
                else {
                    search(r + 1, 0);
                }
            }
            binary_grid[r][c] = 0;
            changes_count--;
            update_parities(r, c, false);
        }
        if (!is_valid_state(r, c)) {
            return;
        }
        if (c < N - 1) {
            search(r, c + 1);
        }
        else {
            search(r + 1, 0);
        }
    }
};

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    int nr_of_test_cases;
    cin >> nr_of_test_cases;

    for (int i = 0; i < nr_of_test_cases; i++) {
        int N;
        cin >> N;

        MinTransformationSearcher mts(N);
        mts.search(0, 0);

        int ans = (mts.min_sol < numeric_limits<int>::max()) ? mts.min_sol : -1;
        cout << "Case " << i + 1 << ": " << ans << '\n'; 
    }
    return 0;
}