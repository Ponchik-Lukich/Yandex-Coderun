#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, x, y, z;
    long long length, squareLength, cubeLength, r1, r2, r3;
    cin >> n;
    cin >> x >> y >> z;
    length = n * (n + 1) / 2 - x;
    squareLength = n * (n + 1) * (2 * n + 1) / 6 - y;
    cubeLength = n * (n + 1) / 2 * (n * (n + 1) / 2) - z;

    vector<long long> a(n), square(n);
    vector<long long> cube(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
        square[i] = a[i] * a[i];
        cube[i] = square[i] * a[i];
    }

    unordered_set<long long> squareSet(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long candidate_r3 = length - a[i] - a[j];
            if (squareSet.find(candidate_r3) != squareSet.end()) {
                if (square[i] + square[j] + candidate_r3 * candidate_r3 == squareLength) {
                    long long cubeSum = cube[i] + cube[j] + (long long) candidate_r3 * candidate_r3 * candidate_r3;
                    if (cubeSum == cubeLength) {
                        r1 = a[i];
                        r2 = a[j];
                        r3 = candidate_r3;
                        break;
                    }
                }
            }
        }
    }
    cout << r1 << " " << r2 << " " << r3;
    return 0;
}
