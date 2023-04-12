#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double sum = 0;
    cin >> n;
    vector<pair<double, double>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        v[i].first = v[i].first / 100 * v[i].second / 100;
        sum += v[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cout << v[i].first / sum << endl;
    }
    return 0;
}