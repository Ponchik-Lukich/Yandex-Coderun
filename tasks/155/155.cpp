#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    std::unordered_map<int, int> hash;
    for (int i = 0; i < n; ++i) {
        hash[v[i]]++;
    }
    int unique = 0;
    for (auto& p : hash) {
        if (p.second == 1) {
            unique++;
        }
    }
    std::cout << unique << std::endl;
    return 0;
}
