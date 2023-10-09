#include <iostream>
int main() {
    int w, k, n, a = 0;
    std::cin >> k >> n >> w;
    for (int i = 1; i <= w; i++) {
        a += k * i;
    }
    if (a > n) {
        std::cout << a - n;
    }
    else {
        std::cout << 0;
    }
    return 0;
}