#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TrieNode {
    uint32_t hash{};
    unordered_map<char, TrieNode*> children;
};

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

void insert(TrieNode* root, const string& word, const uint32_t& hash) {
    TrieNode* cur_node = root;
    for (char c : word) {
        if (!cur_node->children.count(c)) {
            cur_node->children[c] = new TrieNode();
        }
        cur_node = cur_node->children[c];
    }
    cur_node->hash = hash;
}

uint32_t search(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (!node->children[ch]) {
            return {};
        }
        node = node->children[ch];
    }
    return node->hash;
}

uint32_t  calculate_hash(const string& word) {
    size_t n = word.size();
    vector<int> hash(n - 1);
    for (size_t i = 0; i < word.size() - 1; ++i) {
        int result = (word[i] - word[i + 1] + 26) % 26;
        hash[i] = result;
    }
    uint32_t hash1 = fnv1a_hash(hash);
    return hash1;
}

// print trie
void print(TrieNode* root, string& word) {
    if (root->hash) {
        cout << word << "A" << root->hash << endl;
    }
    for (const auto& ch : root->children) {
        word += ch.first;
        word += " ";
        print(ch.second, word);
        word.pop_back();
    }
}

int main() {
    TrieNode* root = new TrieNode();
    unordered_map<string, string> saved;

    string line;
    getline(cin, line);
    istringstream iss(line);
    string word;
    while (iss >> word) {
        uint32_t hash = calculate_hash(word);
        insert(root, word, hash);
    }
    print(root, word);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> word;
        auto it = saved.find(word);
        if (it != saved.end()) {
            cout << it->second << endl;
            continue;
        }
        uint32_t query_sorted_diffs = calculate_hash(word);
        string matched_word;
        for (const auto& ch : root->children) {
            uint32_t word_hash = search(root, ch.first + word);
            if (word_hash == query_sorted_diffs) {
                matched_word = ch.first + word;
                break;
            }
        }
        if (!matched_word.empty()) {
            cout << matched_word << endl;
            saved[word] = matched_word;
        }
    }
    return 0;
}



