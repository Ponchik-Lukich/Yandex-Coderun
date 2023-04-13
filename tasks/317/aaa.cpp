#include <iostream>
#include <tuple>
using namespace std;

tuple<long long, long long, long long> solve_equations(long long a, long long b, long long c) {
    for (long long x = 1; x < a; ++x) {
        for (long long y = 1; y < x; ++y) {
            long long z = a - x - y;
            if (z <= y) {
                break;
            }
            if ((x*x + y*y + z*z == b) && (x*x*x + y*y*y + z*z*z == c) && (x != y) && (y != z) && (x != z)) {
                return make_tuple(x, y, z);
            }
        }
    }
    return make_tuple(0, 0, 0);
}

int main() {
    int n;
    cin >> n;

    long long x, y, z;
    cin >> x >> y >> z;

    long long a_value = n * (n + 1) / 2 - x;
    long long b_value = n * (n + 1) * (2 * n + 1) / 6 - y;
    long long c_value = n * n * (n + 1) * (n + 1) / 4 - z;

    long long r1, r2, r3;
    tie(r1, r2, r3) = solve_equations(a_value, b_value, c_value);

    cout << r1 << " " << r2 << " " << r3;

    return 0;
}
