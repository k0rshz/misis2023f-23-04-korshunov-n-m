#include <iostream>
int main() {
    int n, c = 1440;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int h, m;
        std::cin >> h >> m;
        std::cout << c - h * 60 - m << "\n";
    }
    return 0;
}