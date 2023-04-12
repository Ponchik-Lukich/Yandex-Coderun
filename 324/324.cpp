#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m, limit
    int profit = 0;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());
    if (n > m) {
        limit = m;
    } else {
        limit = n;
    }
    for (int i = 0; i < limit; i++) {
        if (a[i] >= b[i]) {
            break;
        }
        profit += b[i] - a[i];
    }
    cout << profit;
}
