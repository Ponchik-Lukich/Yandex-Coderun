#include <iostream>
#include "string"
#include <unordered_set>

using namespace std;

int main() {
    string s, letters;
    cin >> s;
    cin >> letters;
    unordered_set<char> lettersSet;
    for (char i : letters) {
        lettersSet.insert(i);
    }
    int length = 0;
    int minLength = 0;
    for (char i : s) {
        if (lettersSet.count(i) == 0) {
            if (length < minLength) {
                minLength = length;
            }
            length = 0;
            continue;
        } else {
            length++;
        }
    }
    cout << minLength << endl;
    return 0;
}
