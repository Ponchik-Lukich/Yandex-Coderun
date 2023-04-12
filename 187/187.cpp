#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, min = 1000000000;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        for (int j = 0; j < a.size() - 1; j++) {
            if ((a[j] ^ a[j + 1]) < min) {
                min = a[j] ^ a[j + 1];
            }
        }
        cout << min << endl;
    }
}
