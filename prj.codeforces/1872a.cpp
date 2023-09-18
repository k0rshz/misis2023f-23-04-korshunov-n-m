#include <iostream>
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int k = 0;
        double a, b, c,d;
        std::cin >> a >> b >> c;
        if (a < b) {
            d = a;
            a = b;
            b = d;
        }
        while (a-c > b + c) {
            k++;
            b += c;
            a -= c;
        }
        if (a != b) {
            k++;
        }
        std::cout << k << "\n";
    }
    return 0;
}
