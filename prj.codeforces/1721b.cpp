#include <iostream>
int main() {
    int n;
    std::cin >> n;
    for (int g = 0; g < n; g++) {
        int n, m, sx, sy, d;
        std::cin >> n >> m >> sx >> sy >> d;
        if ((abs(sx-1)<= d && abs(sy - 1) <= d) || (abs(sx - 1) <= d && abs(sx - n) <= d) || (abs(sy - 1) <= d && abs(sy - m) <= d) || (abs(sx - n) <= d && abs(sy - m) <= d)) {
            std::cout << -1<<"\n";
        }
        else {
            std::cout << n + m - 2<<"\n";
        }
    }
    return 0;
}