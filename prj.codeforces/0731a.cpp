#include <iostream>
int main() {
    int k = 0;
    std::string s;
    std::cin >> s;
    char w = 'a';
    for (int i = 0; i < s.size(); i++) {
        char t = s[i];
        k += std::min(26 - abs(w-t), abs(w - t));
        w = t;
    }
    std::cout << k;
    return 0;
}