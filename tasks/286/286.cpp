#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

constexpr int kBase = 27;
constexpr int kMod = 1e9 + 7;


int calculate_shift(const string& word) {
    if (word.empty()) return 0;

    int shift = 0;
    for (size_t i = 1; i < word.size(); ++i) {
        int diff = (word[i] - word[i - 1] + 26) % 26;
        shift = (shift * kBase + diff) % kMod;
    }
    return shift;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, vector<vector<string>>> words;
    string line;
    getline(cin, line);
    istringstream iss(line);
    string word;
    while (iss >> word) {
        int shift = calculate_shift(word);
        if (words.find(shift) == words.end()) {
            words[shift] = vector<vector<string>>(101);
        }
        words[shift][word.size()].push_back(word);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> word;
        int shift = calculate_shift(word);
        int length = word.size();
        if (words.find(shift) != words.end() && !words[shift][length].empty()) {
            cout << words[shift][length][0] << endl;
        }
    }
    return 0;
}

