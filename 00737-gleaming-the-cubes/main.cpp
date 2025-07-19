#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    while (true) {
        int num_cubes;
        cin >> num_cubes;

        if (num_cubes == 0) break;
        
        int x_min[num_cubes], x_max[num_cubes];
        int y_min[num_cubes], y_max[num_cubes];
        int z_min[num_cubes], z_max[num_cubes];
    
        for (int i = 0; i < num_cubes; i++) {
            int x, y, z, len;
            cin >> x >> y >> z >> len;

            x_min[i] = x;
            x_max[i] = x + len;
            y_min[i] = y;
            y_max[i] = y + len;
            z_min[i] = z;
            z_max[i] = z + len;
        }
        int x_overlap = max(0, *min_element(x_max, x_max + num_cubes) - *max_element(x_min, x_min + num_cubes));
        int y_overlap = max(0, *min_element(y_max, y_max + num_cubes) - *max_element(y_min, y_min + num_cubes));
        int z_overlap = max(0, *min_element(z_max, z_max + num_cubes) - *max_element(z_min, z_min + num_cubes));

        cout << x_overlap * y_overlap * z_overlap << '\n';
    }
    return 0;
}