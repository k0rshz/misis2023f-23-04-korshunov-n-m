#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    std::cin >> n;
    for (int i=0; i < n; i++) {
        long long int t;
        int m=1,b=1,k=1;
        std::cin >> t;
        std::vector <long long int> a;
        while (k * k < t && k<100) {
            if (t % k == 0) {
                a.push_back(t / k);
                a.push_back(k);
            }
            k++;
        }
        if (k * k == t) {
            a.push_back(k);
        }
        std::sort(std::begin(a), std::end(a));
        if (a.size() == 1) {
            std::cout << 1 << "\n";
        }
        else {
            for (int j = 0; j < a.size() - 1; j++) {
                if (a[j + 1] - a[j] == 1) {
                    b++;
                    if (b > m) {
                        m = b;
                    }
                }
                else {
                    b = 0;
                }
            }
            std::cout << m << "\n";
        }
    }
    return 0;
}