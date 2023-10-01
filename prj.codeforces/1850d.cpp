#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
int main() {
    int n;
    std::cin >> n;
    for (int g = 0; g < n; g++) {
        int t, c, k = 1;
        std::cin >> t >> c;
        std::vector <int> a;
        std::vector <int> b;
        for (int i = 0; i < t; i++) {
            int e;
            std::cin >> e;
            a.push_back(e);
        }
        for (int i = 0; i < a.size(); i++) {
            if (std::find(std::begin(a), std::end(a), a[i]) != std::end(a)) {
                b.push_back(a[i]);
            }
        }
        std::sort(std::begin(b), std::end(b));
        int f = b.size();
        if (b.size() == 1) {
            std::cout << 0 << "\n";
        }
        else {
            for (int i = 0; i < b.size() - 1; i++) {
                for (int j = i; j < b.size() - 1; j++) {
                    if (abs(a[j] - a[j + 1]) <= c) {
                        k++;
                    }
                    else {
                        break;
                    }
                }
                if (b.size()-k < f) {
                    f = b.size()-k;
                }
                k = 1;
            }
            std::cout << f << "\n";
        }
    }
    return 0;
}