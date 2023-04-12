#include <iostream>
#include <cmath>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    long x, y, v;
    std::cin >> x >> y;
    if (x == y) {
        std::cout << 1 << std::endl;
        return 0;
    }
    if (y % x != 0) {
        std::cout << 0 << std::endl;
        return 0;
    }
    v = 2;
    long div = y / x;
    vector <long> divisors1;
    unordered_set <long> divisors;
    while (v * v <= div) {
        if (div % v > 0) {
            v++;
            continue;
        }
        divisors1.push_back(v);
        div /= v;
    }
    if (div > 1) {
        divisors1.push_back(div);
    }
    for (long & i : divisors1) {
        divisors.insert(i);
    }
    std::cout << pow(2, divisors.size()) << std::endl;
    return 0;
}