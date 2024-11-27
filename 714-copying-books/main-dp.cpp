#include <bits/stdc++.h>
using namespace std;

class FindOpt {
public:
    int m, k, curr_cost, opt;
    vector<int> books, splits, opt_split;

    FindOpt(int m, int k) : m(m), k(k), curr_cost(0), opt(INT_MAX), books(m) {}

    void print_opt() {
        int start = 0;

        for (int split_i : opt_split) {
            for (int i = start; i <= split_i; ++i) {
                cout << books[i];

                if (!(split_i == m - 1 && i == split_i)) cout << " ";
            }
            if (split_i < m - 1) {
                start = split_i + 1;
                cout << "/ ";
            }
        }
        cout << '\n';
    }

    int sum(int start, int end) {
        int sum = 0;

        for (int i = start; i <= end; ++i) {
            sum += books[i];
        }
        return sum;
    }

    void search(int scribe_i, int book_i) {
        if (scribe_i == k - 1) {
            curr_cost = max(curr_cost, sum(book_i, m - 1));

            if (curr_cost < opt) {
                opt = curr_cost;
                opt_split = vector<int>(splits);
                opt_split.push_back(m - 1);
            }
            return;
        }
        for (int i = book_i; m - i >= k - scribe_i; ++i) {
            int prev = curr_cost;
            curr_cost = max(curr_cost, sum(book_i, i));

            if (curr_cost > opt) return;
            
            splits.push_back(i);
            search(scribe_i + 1, i + 1);
            splits.pop_back();

            curr_cost = prev;
        }
    }
};

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    int N;
    cin >> N;

    for (int _ = 0; _ < N; ++_) {
        int m, k;
        cin >> m >> k;
        FindOpt fo(m, k);

        for (int i = 0; i < m; i++) {
            cin >> fo.books[i];
        }
    fo.search(0, 0);
    fo.print_opt();
    // cout << "min cost: " << fo.opt << '\n';
    }
    return 0;
}