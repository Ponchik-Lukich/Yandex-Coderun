#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <unordered_map>
using namespace std;

long long calculate_result(const string& word) {
    long long result = 0;
    for (long long i = 0; i < word.size() - 1; ++i) {
        result += (word[i] - word[i + 1] + 26) % 26;
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
                    set <int> diffs;
                    int flag = 1;
                    for (size_t j = 0; j < word.size(); ++j) {
                        int dif = (s[j] - word[j] + 26) % 26;
                        if (diffs.find(dif) != diffs.end() && diffs.size() == 1) {
                            flag = 0;
                            break;
                        } else {
                            diffs.insert(dif);
                        }
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

