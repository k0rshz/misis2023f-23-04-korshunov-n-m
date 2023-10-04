#include <iostream>
#include <vector>
int main() {
    int n,ch=0,k=0;
    std::cin >> n;
    std::vector <int> a;
    for (int i = 0; i < 7; i++) {
        int t;
        std::cin >> t;
        a.push_back(t);
    }
    while (ch < n) {
        if (k < 6) {
            ch += a[k];
            k++;
        }
        else {
            ch += a[k];
            k = 0;
        }
    }
    if (k == 0) {
        std::cout << 7;
    }
    else {
        std::cout << k;
    }
    return 0;
}
