#include <iostream>
#include <algorithm>
#include <set>
#include "string"

using namespace std;

bool check(int length, int height, const set<pair<int, int>>& first, const set<pair<int, int>>& second) {
    for (const auto& i : first) {
        int x = i.first;
        int y = i.second;
        if (second.find({x + 1, y + 1}) != second.end()) {
            if (x + 2 <= length && y + 2 <= height) {
                if (first.find({x + 2, y + 2}) == first.end() && second.find({x + 2, y + 2}) == second.end()) {
                    return true;
                }
            }
        }
        if (second.find({x + 1, y - 1}) != second.end()) {
            if (x + 2 <= length && y - 2 >= 1) {
                if (first.find({x + 2, y - 2}) == first.end() && second.find({x + 2, y - 2}) == second.end()) {
                    return true;
                }
            }
        }
        if (second.find({x - 1, y + 1}) != second.end()) {
            if (x - 2 >= 1 && y + 2 <= height) {
                if (first.find({x - 2, y + 2}) == first.end() && second.find({x - 2, y + 2}) == second.end()) {
                    return true;
                }
            }
        }
        if (second.find({x - 1, y - 1}) != second.end()) {
            if (x - 2 >= 1 && y - 2 >= 1) {
                if (first.find({x - 2, y - 2}) == first.end() && second.find({x - 2, y - 2}) == second.end()) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int n, m, w, b;
    string s;
    cin >> n >> m;
    cin >> w;
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
    bool res;
    if (s == "white") {
        res = check(n, m,  wp, bp);
    } else {
        res =  check(n, m, bp, wp);
    }
    if (res) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
