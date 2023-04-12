#include <iostream>
#include <algorithm>
#include <set>
#include "string"

using namespace std;

int main() {
    int n, m, w, b;
    string s;
    cin >> n >> m;
    cin >> w;
    // create set of pairs
    set<pair<int, int>> wp;
    for (int i = 0; i < w; i++) {
        int x, y;
        cin >> x >> y;
        wp.insert({x, y});
    }
    cin >> b;
    set<pair<int, int>> bp;
    for (int i = 0; i < b; i++) {
        int x, y;
        cin >> x >> y;
        bp.insert({x, y});
    }
    cin >> s;
    if (s == "white") {
        for (const auto& i : wp) {
            
        }
    } else {
        for (const auto& i : bp) {
            cout << i.first << " " << i.second << endl;
        }
    }
}
