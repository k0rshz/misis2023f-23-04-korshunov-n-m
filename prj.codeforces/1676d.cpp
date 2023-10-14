#include <iostream>
#include <vector>
int main() {
    int w;
    std::cin >> w;
    for (int g = 0; g < w; g++) {
        int n, m;
        std::cin >> n >> m;
        //int a[100][100];
        std::vector <std::vector <int>> a(n, std::vector <int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int t;
                std::cin >> t;
                //a[i].push_back(t);
                a[i][j] = t;
            }
        }
        int b, c, k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ch = 0;
                for (int e = 0; e < n; e++) {
                    for (int f = 0; f < m; f++) {
                        if (i + j == e + f || abs(i - e) == abs(j - f)) {
                            ch += a[e][f];
                        }
                    }
                }
                if (ch > k) {
                    k = ch;
                    b = i;
                    c = j;
                }
            }
        }
        std::cout << k << "\n";
    }
    return 0;
}