#include <iostream>

int main() {
    int a, b, c ,tmp;
    std::cin >> a >> b >> c;
    if (a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    if (a > c) {
        tmp = a;
        a = c;
        c = tmp;
    }
    if (b > c) {
        tmp = b;
        b = c;
        c = tmp;
    }
    std::cout << b;
    return 0;
}
