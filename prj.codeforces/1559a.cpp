#include <iostream>
#include <vector>
int main() {
    int m;
    std::cin >> m;
    for (int g = 0; g < m; g++) {
        int n,s=0,q;
        std::cin >> n;
        std::vector <int> a;
        for (int i = 0; i < n; i++) {
            int t;
            std::cin >> t;
            if (t >=s) {
                q = i;
                s = t;
            }
            a.push_back(t);
        }
        for (int s = 0; s < 10; s++) {
            for (int i = n - 1; i > 0; i--) {
                for (int j = 0; j <= i; j++) {
                    int k = i - j, z = j;
                    while (k >= 0) {
                        k--;
                        int t = a[z] & a[i - z];
                        a[z] = t;
                        z++;
                    }
                }
            }
        }
        std::cout << a[q] << "\n";
    }
    return 0;
}