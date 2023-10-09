#include <iostream>
int main() {
    int n, m, k = -10000000000;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        if (b > m) {
            if (k < a - (b - m)) {
                k = a - (b - m);
            }
        }
        else {
            if (k < a) {
                k = a;
            }
        }
    }
    std::cout << k;
    return 0;
}