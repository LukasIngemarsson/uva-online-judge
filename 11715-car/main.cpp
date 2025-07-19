#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int case_count = 1;
    int case_;
    double vars[3];
    pair<double, double> ans;

    while (true) {
        cin >> case_;

        if (case_ == 0) {
            break;
        }
        cin >> vars[0] >> vars[1] >> vars[2];

        switch(case_) {
            case 1:
                ans.first = ((vars[0] + vars[1]) / 2) * vars[2];
                ans.second = (vars[1] - vars[0]) / vars[2];
                break;
            case 2:
                ans.second = (vars[1] - vars[0]) / vars[2];
                ans.first = ((vars[0] + vars[1]) / 2) * ans.second;
                break;
            case 3:
                ans.first = sqrt(pow(vars[0], 2) + 2 * vars[1] * vars[2]);
                ans.second = vars[2] / ((ans.first + vars[0]) / 2);
                break;
            case 4:
                ans.first = sqrt(pow(vars[0], 2) - 2 * vars[1] * vars[2]);
                ans.second = vars[2] / ((vars[0] + ans.first) / 2);
                break;
        }
        cout << fixed << setprecision(3);
        cout << "Case " << case_count << ": " << ans.first << " " << ans.second << '\n';
        case_count++;
    }
    return 0;
}