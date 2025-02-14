#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    string line;

    while (cin >> line) {
        list<char> out;
        char curr;
        bool at_home = false;
        int home_index = 0;

        for (char curr: line) {
            if (curr == '[') {
                at_home = true;
                home_index = 0;
            }
            else if (curr == ']') {
                at_home = false;
            }
            else if (at_home) {
                out.insert(next(out.begin(), home_index), curr);
                home_index++;
            }
            else {
                out.push_back(curr);
            }
        }
        string out_str(out.begin(), out.end());
        cout << out_str << '\n';
    }
    return 0;
}