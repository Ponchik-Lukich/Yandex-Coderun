#include <iostream>
#include <string>

using namespace std;

int main() {
    string j;
    string s;
    cin >> j >> s;
    int count = 0;
    for (char i : s) {
        for (char k : j) {
            if (i == k) {
                count++;
                break;
            }
        }
    }
    cout << count;
    return 0;
}
