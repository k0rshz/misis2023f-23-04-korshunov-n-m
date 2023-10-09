#include <iostream>
#include <cmath>
int main() {
    int n = 1, m = 0, a, b, c;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> c;
            m++;
            if (c == 1) {
                a = n;
                b = m;
            }
        }
        m = 0;
        n++;
    }
    std::cout << abs(a - 3) + abs(b - 3);
    return 0;
}