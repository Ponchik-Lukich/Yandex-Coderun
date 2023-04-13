#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    int64_t n;
    int64_t x, y, z, r1, r2, r3;
    cin >> n;
    cin >> x >> y >> z;

    int64_t length = n * (n + 1) / 2 - x;
    int64_t squareLength = n * (n + 1) * (2 * n + 1) / 6 - y;
    int64_t cubeLength = n * (n + 1) / 2 * (n * (n + 1) / 2) - z;

    vector<int64_t> a(n), square(n), cube(n);

    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
        square[i] = a[i] * a[i];
        cube[i] = square[i] * a[i];
    }

    bool found = false;
    for (int i = 0; i < n && !found; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int64_t candidate_r3 = length - a[i] - a[j];
            if (candidate_r3 >= 1 && candidate_r3 <= n) {
                if (square[i] + square[j] + candidate_r3 * candidate_r3 == squareLength) {
                    int64_t cubeSum = cube[i] + cube[j] + candidate_r3 * candidate_r3 * candidate_r3;
                    if (cubeSum == cubeLength && a[j] != candidate_r3 && a[i] != candidate_r3 && a[i] != a[j] && (1 <= candidate_r3 && candidate_r3 <= n) && (1 <= a[i] && a[i] <= n) && (1 <= a[j] && a[j] <= n)) {
                        r1 = a[i];
                        r2 = a[j];
                        r3 = candidate_r3;
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    cout << r1 << " " << r2 << " " << r3;
    return 0;
}
