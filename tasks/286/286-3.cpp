#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

string calculate_shift(const string& word) {
    if (word.empty()) return "";

    stringstream ss;
    for (size_t i = 1; i < word.size(); ++i) {
        int shift = (word[i] - word[i - 1] + 26) % 26;
        ss << shift << ',';
    }
    return ss.str();
}

int main() {
    unordered_map<string, unordered_map<int, vector<string>>> words;
    string line;
    getline(cin, line);
    istringstream iss(line);
    string word;
    while (iss >> word) {
        words[calculate_shift(word)][word.size()].push_back(word);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> word;
        string shift = calculate_shift(word);
        int length = word.size();
        if (words.find(shift) != words.end() && words[shift].find(length) != words[shift].end()) {
            cout << words[shift][length][0] << endl;
        }
    }
    return 0;
}


