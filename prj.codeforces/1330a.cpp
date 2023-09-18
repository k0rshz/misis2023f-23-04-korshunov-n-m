#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int s;
    std::cin >> s;
    for (int i = 0; i < s; i++) {
        int n, x;
        std::cin >> n >> x;
        std::vector <int> a(n);
        for (int j = 0; j < n; j++) {
            std::cin >> a[j];
        }
        sort(a.begin(), a.end());
        int m = a[n - 1];
        std::vector <int> b;
        for (int j = 1; j <= m; j++) {
            int k = 0;
            for (int g = 0; g < n; g++) {
                if (a[g] == j) {
                    k = 1;
                    break;
                }
            }
            b.push_back(k);
        }
        for (int j = 0; j < x; j++) {
            b.push_back(0);
        }
        int k0 = 0, k = 0;
        for (int j = 0; j < b.size(); j++) {
            if (x == 0) {
                break;
            }
            if (k0 == x && b[j] == 0) {
                break;
            }
            if (b[j] == 0) {
                k0 += 1;
            }
            k++;
        }
        std::cout << k << "\n";
    }
    return 0;
}