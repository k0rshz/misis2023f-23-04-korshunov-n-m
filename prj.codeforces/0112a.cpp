#include <iostream>
int main() {
    std::string a, b, c = "", d = "";
    std::cin >> a >> b;
    int k = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= 97 && a[i] <= 122) {
            c += a[i] - 32;
        }
        else {
            c += a[i];
        }
        if (b[i] >= 97 && b[i] <= 122) {
            d += b[i] - 32;
        }
        else {
            d += b[i];
        }
        if (c < d) {
            k = -1;
            break;
        }
        else if (c > d) {
            k = 1;
            break;
        }
    }
    std::cout << k;
    return 0;
}