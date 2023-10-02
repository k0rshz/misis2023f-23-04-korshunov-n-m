#include <iostream>
#include <vector>
int main() {
    int n, m,s=1;
    long long int k = 0;
    std::cin >> n >> m;
    std::vector <int> a;
    for (int i = 0; i < m; i++) {
        int b;
        std::cin >> b;
        a.push_back(b);
    }
    for (int i = 0; i < m; i++) {
        if (a[i]-s>=0) {
            k += a[i] - s;
        }
        else {
            k += n-(s - a[i]);
        }
        s = a[i];
    }
    std::cout << k;
    return 0;
}