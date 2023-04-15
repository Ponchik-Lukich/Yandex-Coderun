#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    int n, m, q;
    string path;
    unordered_set<string> dirs, files, paths;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> path;
        dirs.insert(path);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> path;
        for (auto &dir: dirs) {
            if (path.rfind(dir, 0) == 0) {
                files.insert(path);
                break;
            }
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        unordered_map<string, int> map;
        unordered_set<string> set;
        string ex;
        cin >> path;
        paths.insert(path);
        for (auto &file: files) {
            if (file.rfind(path, 0) == 0) {
                ex = file.substr(file.find_last_of('.'));
                set.insert(ex);
                map[ex] += 1;
            }
        }
        cout << set.size() << endl;
        for (auto &item: map) {
            cout << item.first << ": " << item.second << endl;
        }

    }
    return 0;
}