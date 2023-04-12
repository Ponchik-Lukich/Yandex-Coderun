#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;
int main() {
    int t;
    cin >> t;
    int edges = 0;
    set <string> vertices;
    map<pair<string, string>, int> map;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size() - 3; j++) {
            string sub1 = s.substr(j, 3);
            string sub2 = s.substr(j + 1, 3);
            if (vertices.find(sub1) == vertices.end()) {
                vertices.insert(sub1);
            }
            if (vertices.find(sub2) == vertices.end()) {
                vertices.insert(sub2);
            }
            if (map.find({sub1, sub2}) == map.end()) {
                map[{sub1, sub2}] = 1;
                edges++;
            } else {
                map[{sub1, sub2}]++;
            }
        }
    }
    cout << vertices.size() << endl;
    cout << edges << endl;
    for(const auto& i: map) {
        cout << i.first.first << " " << i.first.second << " " << i.second << endl;
    }
}
