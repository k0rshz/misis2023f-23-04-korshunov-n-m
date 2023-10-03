#include <iostream>
int main() {
    int m;
    std::cin >> m;
    for (int g = 0; g < m; g++) {
        int n, k, res = 0;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'B') {
                res += 1;
                i += k - 1;
            }
        }
        std::cout << res << "\n";
    }
    return 0;
}