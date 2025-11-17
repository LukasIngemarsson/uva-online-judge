#include <bits/stdc++.h>
using namespace std;

/*
@brief Finds the longest increasing subsequence for a given sequence of numbers.

@param nums: The sequence of numbers.

@return A vector containing the indices of the elements in the longest increasing subsequence.

@note Time complexity: `O(n * log(n))`, where `n` is the number of elements in the total sequence.
*/
vector<int> lis(vector<int>& nums) { 
    vector<int> seq; // stores the current ascending set of numbers
    vector<int> idxs; // stores the index of the corresponding numbers in seq
    vector<int> parent(nums.size(), -1); // stores the index of the parent of a number/element

    for (int i = 0; i < nums.size(); ++i) {
        // binary search to find index of the first number currently in the sequence,
        // that is not less than the candidate number nums[i]
        int pos = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
        if (pos == seq.size()) { // no number in the current sequence is >= the candidate num
            seq.push_back(nums[i]);
            idxs.push_back(i);
        }
        else {
            seq[pos] = nums[i];
            idxs[pos] = i;
        }
        if (pos > 0) {
            parent[i] = idxs[pos-1];
        }
    }

    vector<int> lis_idxs;
    for (int i = idxs.back(); i >= 0; i = parent[i]) {
        lis_idxs.push_back(i);
    }
    reverse(lis_idxs.begin(), lis_idxs.end());

    return lis_idxs;
}

vector<int> split_to_int_vect(const string& s) {
    istringstream iss(s);
    return vector<int>(istream_iterator<int>(iss), istream_iterator<int>());
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    string s;
    getline(cin, s);
    int n = stoi(s);

    while(getline(cin, s)) {
        vector<int> true_event_ranks = split_to_int_vect(s);

        while (getline(cin, s)) {
            vector<int> event_ranks = split_to_int_vect(s);
            if (event_ranks.size() == 1) {
                n = event_ranks[0];
                goto next;
            }
            vector<int> ordered_events(n);
            for (int i = 0; i < n; ++i)
                ordered_events[event_ranks[i]-1] = true_event_ranks[i];

            auto lis_idxs = lis(ordered_events);
            cout << lis_idxs.size() << '\n';
        }
        break;
        next:;
    }

    return 0;
}
