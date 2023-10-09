#include <iostream>
#include <cmath>
int main() {
    int a;
    std::cin >> a;
    for (int i = 0; i < a; i++) {
        int b, k = 0, c, d = 0, n = 0;
        std::cin >> b;
        c = b;
        while (c > 9) {
            d += c % 10;
            c /= 10;
        }
        if (d == 0) {
            k = 1;
        }
        if ((b >= 1 && b <= 9) || (k == 1)) {
            std::cout << 1 << "\n" << b << "\n";
        }
        else {
            k = 0;
            c = b;
            while (c > 0) {
                if (c % 10 != 0) {
                    n++;
                }
                k++;
                c /= 10;
            }
            d = k;
            std::cout << n << "\n";
            for (int i = 0; i < k; i++) {
                int g;
                g = b / int(pow(10, d - 1)) * int(pow(10, d - 1));
                if (g != 0) {
                    std::cout << g << " ";
                }
                b = b % int(pow(10, d - 1));
                d--;
            }
            std::cout << "\n";
        }
    }
    return 0;
}