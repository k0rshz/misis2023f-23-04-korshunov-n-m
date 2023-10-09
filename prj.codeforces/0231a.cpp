#include <iostream>
int main() {
    int n, k = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a + b + c > 1) {
            k++;
        }
    }
    std::cout << k;
    return 0;
}