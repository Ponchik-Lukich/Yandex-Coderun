#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int n, m, q, c;
    cin >> n >> m;
    unordered_map<int, map<int, unordered_set<int>>> molecule;
    for (int i = 1; i <= n; ++i) {
        molecule[i] = map<int, unordered_set<int>>();
    }
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        molecule[x][y].insert(i);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> c;
        size_t size = molecule.size();
        unordered_set<int> toDelete;
        for (auto & it : molecule) {
            for (auto & it2 : it.second) {
                if (it2.second.find(c) != it2.second.end()) {
                    it2.second.erase(c);
                    if (it2.second.empty()) {
                        it.second.erase(it2.first);
                        break;
                    }
                    toDelete.insert(it2.first);
                    break;
                }
                toDelete.insert(it2.first);
            }
        }
        if (size - toDelete.size() == 0) {
            cout << 1 << ' ';
        }
        cout << size - toDelete.size() << ' ';
    }
    return 0;
}