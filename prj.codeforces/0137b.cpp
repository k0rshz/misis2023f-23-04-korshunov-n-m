#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n,k=0;
    std::cin >> n;
    std::vector <int> b;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        b.push_back(a);
    }
    std::sort(std::begin(b), std::end(b));
    for (int i = 1; i <= n; i++) {
        int flag = 0;
        for (int j = 0; j < b.size(); j++) {
            if (b[j] == i) {
                flag = 1;
            }
        }
        if (flag != 1) {
            k++;
        }
    }
    std::cout << k;
}