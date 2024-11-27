#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AttackingRooks {
public:
    int N;
    vector<vector<int>> grid; // 0: empty, 1: pawn, 2: rook

    int num_rooks;
    int max_rooks;

    AttackingRooks(int N) : N(N) {
        grid = vector<vector<int>>(N, vector<int>(N, 0));
        num_rooks = 0, max_rooks = 0;
        char ch;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                cin >> ch;

                if (ch == 'X') grid[r][c] = 1;
            }
        }
    }

    bool is_valid_state(int r, int c) {
        for (int ci = c - 1; ci >= 0; ci--) {
            if (grid[r][ci] == 1) {
                break;
            }
            else if (grid[r][ci] == 2) {
                return false;
            }
        }
        for (int ri = r - 1; ri >= 0; ri--) {
            if (grid[ri][c] == 1) {
                break;
            }
            else if (grid[ri][c] == 2) {
                return false;
            }
        }
        return true;
    }

    void search(int r, int c) {
        if (num_rooks > max_rooks) max_rooks = num_rooks;

        if (r >= N || num_rooks + ((((N - 1) - r)) * N + (N - c)) < max_rooks) {
            return;
        }

        if (grid[r][c] == 0 && is_valid_state(r, c)) {
            grid[r][c] = 2;
            num_rooks++;

            for (int ci = c + 1; ci + 1 < N; ci++) {
                if (grid[r][ci] == 1) {
                    search(r, ci + 1);
                    goto row_elem_searched;
                }
            }
            search(r + 1, 0);

            row_elem_searched:
            grid[r][c] = 0;
            num_rooks--;
        }
        if (c + 1 < N) {
            search(r, c + 1);
        }
        else {
            search(r + 1, 0);
        }
    }
};

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    int N;

    while (cin >> N) {
        AttackingRooks ar(N);
        ar.search(0, 0);
        cout << ar.max_rooks << '\n';
    }
    return 0;
}