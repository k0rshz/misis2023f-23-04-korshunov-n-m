#include <iostream>
int main() {
    int m;
    std::cin >> m;
    for (int g = 0; g < m; g++) {
        int n, k, x, c=0, f=0;
        std::cin >> n >> k >> x;
        if ((x + 1 < k) || (n<k)) {
            std::cout << -1 << "\n";
        }
        else {
            for (int i = 0; i < k; i++) {
                c += i;
                f++;
            }
            while (f < n) {
                f++;
                if (x != k) {
                    c += x;
                }
                else {
                    c += x - 1;
                }
            }
            std::cout << c << "\n";
        }
    }
    return 0;
}