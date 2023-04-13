#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    std::unordered_map<int, int> hash;
    for (int i = 0; i < n; ++i) {
        hash[a[i]]++;
    }
    int max = -1;
    int maxNum = -1;
    for (auto& p : hash) {
        if (p.second > max) {
            max = p.second;
            maxNum = p.first;
        } else if (p.second == max) {
            if (p.first > maxNum) {
                maxNum = p.first;
            }
        }
    }
    cout << maxNum;
    return 0;
}
