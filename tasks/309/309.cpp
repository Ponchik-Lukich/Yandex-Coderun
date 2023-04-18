#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    map<int, set<pair<int, int>>> molecule;
    for (int i = 1; i <= n; ++i) {
        molecule[i] = set<pair<int, int>>{};
    }

    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        molecule[x].insert(make_pair(y, i));
    }

    int q;
    cin >> q;

    vector<int> arr(q);
    for (int i = 0; i < q; ++i) {
        cin >> arr[i];
    }

    for (const int &c : arr) {
        vector<set<int>> clusters;
        for (auto &[key, value] : molecule) {
            set<int> s{key};
            set<pair<int, int>> value_copy = value;
            for (const auto &[x, i] : value) {
                if (i == c) {
                    value_copy.erase(make_pair(x, i));
                    continue;
                }
                s.insert(x);
            }
            value.clear();
            value.insert(value_copy.begin(), value_copy.end());
            clusters.push_back(s);
        }

        while (true) {
            bool updated = false;
            for (size_t i = 0; i < clusters.size(); ++i) {
                for (size_t j = i + 1; j < clusters.size(); ++j) {
                    if (any_of(clusters[i].begin(), clusters[i].end(), [&clusters, j](int x) {
                        return clusters[j].count(x) > 0;
                    })) {
                        clusters[i].insert(clusters[j].begin(), clusters[j].end());
                        clusters.erase(clusters.begin() + j);
                        updated = true;
                        break;
                    }
                }
                if (updated) break;
            }
            if (!updated) break;
        }

        cout << clusters.size() << " ";
    }

    return 0;
}

