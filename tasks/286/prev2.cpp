#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

long long calculate_result(const string& word) {
    size_t n = word.size();
    vector<long long> sorted_diff(n - 1);
    for (int i = 0; i < n; ++i) {
        sorted_diff[i] = (word[i] - word[i + 1] + 26) % 26;
    }
    sort(sorted_diff.begin(), sorted_diff.end());
    long long result = 0;
    for (size_t i = 0; i < n - 1; ++i) {
        result = result * 26 + sorted_diff[i];
    }
    return result;
}

int main() {
    unordered_map<long long, vector<string>> m;
    unordered_map<string , string> saved;

    string line;
    getline(cin, line);
    istringstream iss(line);
    string word;
    while (iss >> word) {
        m[calculate_result(word)].push_back(word);
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
        long long result = calculate_result(word);
        auto it1 = m.find(result);
        if (it1 != m.end()) {
            if (it1->second.size() == 1) {
                cout << it1->second[0] << endl;
                saved[word] = it1->second[0];
                continue;
            }
            for (const auto& s : it1->second) {
                if (s.size() == word.size()) {
                    int prev = -31;
                    int flag = 1;
                    for (size_t j = 0; j < word.size(); ++j) {
                        int dif = (s[j] - word[j] + 26) % 26;
                        if (prev != -31 && prev != dif) {
                            flag = 0;
                            break;
                        }
                        prev = dif;
                    }
                    if (flag) {
                        cout << s << endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}