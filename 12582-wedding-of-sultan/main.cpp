#include <iostream>
#include <string>
#include <map>

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    int nr_of_test_cases;
    std::cin >> nr_of_test_cases;

    for (int i = 0; i < nr_of_test_cases; i++) {
        std::string line;
        std::cin >> line;
        std::string stack;
        int line_len = line.size();
        std::map<char, int> counts; 

        std::cout << "Case " << i + 1 << '\n';

        for (int j = 0; j < line_len; j++) {
            char next = line[j];

            if (j > 0) {
                if (stack.back() == next) {
                    stack.pop_back();
                    continue;
                }
                else {
                    counts[stack.back()] += 1;
                    counts[next] += 1;
                }
            }
            stack.push_back(line[j]);
        }
        for (auto& kvp : counts) {
            std::cout << kvp.first << " = " << kvp.second << '\n';
        }
    }
    return 0;
}