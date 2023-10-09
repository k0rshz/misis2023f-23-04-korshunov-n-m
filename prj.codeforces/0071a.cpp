#include <iostream>
int main() {
    int n;
    std::cin >> n;
    int k = 0;
    for (int i = 0; i < n; i++) {
        std::string a;
        std::cin >> a;
        a = a + " ";
        int k = 0;
        while (a[k] != ' ') {
            k++;
        }
        if (k > 10) {
            std::cout << a[0] << k - 2 << a[k - 1] << "\n";
        }
        else {
            std::cout << a << "\n";
        }
    }
    return 0;
}