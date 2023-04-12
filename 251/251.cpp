#include <iostream>
#include "string"

using namespace std;

int lengthOfMinFullSubstring(string s, string letters) {
    string newStr;
    int minLength = -1;
    for (char i: s) {
        if (letters.find(i) == string::npos) {
            newStr = "";
            continue;
        }
        newStr += i;
        int flag = 0;
        int min_position = newStr.size();
        for (char j: letters) {
            int position = newStr.find_last_of(j);
            if (position != string::npos) {
                flag++;
                if (position < min_position) {
                    min_position = position;
                }
            }
        }
        if (flag == letters.size()) {
            newStr.erase(0, min_position);
            if (minLength == -1) {
                minLength = newStr.size();
            } else {
                minLength = min(minLength, (int) newStr.size());
            }
        }
    }
    return minLength;
}

int main() {
    string s, letters;
    int res;
    cin >> s;
    cin >> letters;
    if (s.size() < letters.size()) {
        cout << 0;
        return 0;
    }
    res = lengthOfMinFullSubstring(s, letters);
    if (res == -1) {
        cout << 0;
    } else {
        cout << res;
    }
    return 0;
}