#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void dfs(int vertex, unordered_map<int, set<pair<int, int>>> &molecule, set<int> &visited) {
    visited.insert(vertex);
    for (auto &it: molecule[vertex]) {
        if (visited.find(it.first) == visited.end()) {
            dfs(it.first, molecule, visited);
        }
    }
}

int countComponents(unordered_map<int, set<pair<int, int>>> &molecule) {
    set<int> visited;
    int count = 0;
    for (auto &it: molecule) {
        if (visited.find(it.first) == visited.end()) {
            dfs(it.first, molecule, visited);
            ++count;
        }
    }
    return count;
}


int main() {
    int n, m, q, c;
    cin >> n >> m;
    unordered_map<int, set<pair<int, int>>> molecule;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        molecule[x].insert({y, i});
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> c;
        for (auto &it: molecule) {
            for (auto &it2: it.second) {
                if (it2.second == c) {
                    it.second.erase(it2);
                    break;
                }
            }
        }
        cout << countComponents(molecule) << ' ';
    }
    return 0;
}