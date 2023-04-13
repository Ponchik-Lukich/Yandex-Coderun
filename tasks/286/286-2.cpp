#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
using namespace std;

map<vector<int>, uint32_t> memo;

uint32_t fnv1a_hash(const vector<int>& data) {
    if (memo.find(data) != memo.end()) {
        return memo[data];
    }

    const uint32_t FNV_OFFSET_BASIS = 2166136261;
    const uint32_t FNV_PRIME = 16777619;

    uint32_t hash = FNV_OFFSET_BASIS;

    for (int value : data) {
        hash ^= value;
        hash *= FNV_PRIME;
    }

    memo[data] = hash;
    return hash;
}

int main() {
    set<string> words;
    string line;
    getline(cin, line);
    istringstream iss(line);
    string word;
    while (iss >> word) {
        words.insert(word);
    }

    map<uint32_t, string> m;
    for (const auto& s : words) {
        vector<int> v(s.size() - 1);
        for (size_t i = 0; i < s.size() - 1; ++i) {
            int result = (s[i] - s[i + 1] + 26) % 26;
            v[i] = result;
        }
        uint32_t hash = fnv1a_hash(v);
        m[hash] = s;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> word;
        vector<int> v(word.size() - 1);
        for (size_t j = 0; j < word.size() - 1; ++j) {
            int result = (word[j] - word[j + 1] + 26) % 26;
            v[j] = result;
        }
        uint32_t hash = fnv1a_hash(v);
        auto it = m.find(hash);
        if (it != m.end()) {
            cout << it->second << endl;
        }
    }
    return 0;
}
