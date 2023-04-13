#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <unordered_map>
using namespace std;


uint32_t fnv1a_hash(const vector<int>& data) {

    const uint32_t FNV_OFFSET_BASIS = 2166136261;
    const uint32_t FNV_PRIME = 16777619;

    uint32_t hash = FNV_OFFSET_BASIS;

    for (int value : data) {
        hash ^= value;
        hash *= FNV_PRIME;
    }

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

    unordered_map<uint32_t, string> m;
    unordered_map<string , string> saved;
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
        auto it = saved.find(word);
        if (it != saved.end()) {
            cout << it->second << endl;
            continue;
        }
        vector<int> v(word.size() - 1);
        for (size_t j = 0; j < word.size() - 1; ++j) {
            int result = (word[j] - word[j + 1] + 26) % 26;
            v[j] = result;
        }
        uint32_t hash = fnv1a_hash(v);
        cout << m[hash] << endl;
        saved[word] = m[hash];
    }
    return 0;
}
