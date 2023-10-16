#include <iostream>
#include <vector>
int main() {
    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        std::vector <int> a;
        int n,k=1,p=0,c=0;
        std::cin >> n;
        for (int j = 0; j < n; j++) {
            int t;
            std::cin >> t;
            a.push_back(t);
        }
        for (int j = 0; j < n; j++) {
            if (p == 2 || (p==1 && a[j]==0)) {
                k = -1;
                break;
            }
            else if (a[j] == 0) {
                p += 1;
                c = 0;
            }
            else if (c >= 1 && a[j] == 1) {
                k += 5;
                p = 0;
                c ++;
            }
            else {
                k += 1;
                c++;
                p = 0;
            }
        }
        std::cout << k << "\n";
    }
    return 0;
}