#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    int N;
    cin >> N;

    for (int _ = 0; _ < N; ++_) {
        int m, k;
        cin >> m >> k;
        vector<int> books(m);

        for (int i = 0; i < m; i++) {
            cin >> books[i];
        }
        reverse(books.begin(), books.end());
        pair<ll, ll> thres = {0, 1e16};
        vector<int> prev_state;
        ll prev_max_sum = 1e16;

        // int count = 0;
        while (thres.second - thres.first > 1) { 
            ll x = (thres.second + thres.first) / 2;
            ll curr_max_sum = 0;
            int last_book_i = 0;
            vector <int> curr_state;

            for (int scribe_i = 0; scribe_i < k; ++scribe_i) {
                ll sum = 0;

                for (int i = last_book_i; m - i >= k - scribe_i; ++i) {
                    if (sum + books[i] <= x) {
                        sum += books[i];

                        if (m - i == k - scribe_i) {
                            curr_state.push_back(i);
                            last_book_i = i + 1;
                        }
                    }
                    else {
                        if (i == last_book_i || scribe_i == k - 1) {
                            thres.first = x;
                            goto out;
                        }
                        else {
                            last_book_i = i;
                            curr_state.push_back(last_book_i - 1);
                        }
                        break;
                    }
                }
                if (sum > curr_max_sum) curr_max_sum = sum;
            }
            prev_max_sum = curr_max_sum;
            prev_state = move(curr_state);
            thres.second = prev_max_sum;

            out:;
        }
        int start = 0;
        vector<string> ans;

        for (int split_i : prev_state) {
            for (int i = start; i <= split_i; ++i) {
                ans.push_back(to_string(books[i]));

                if (!(split_i == m - 1 && i == split_i)) {
                    ans.push_back(" ");
                }
            }
            if (split_i < m - 1) {
                start = split_i + 1;
                ans.push_back(" /");
            }
        }
        reverse(ans.begin(), ans.end());

        for (auto &str_ : ans) {
            cout << str_;
        }
        cout << '\n';
    }
    return 0;
}