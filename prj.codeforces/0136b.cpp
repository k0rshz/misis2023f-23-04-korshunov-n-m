#include <iostream>
#include <string>
#include <cmath>
std::string tr(int x) {
    std::string s = "";
    while (x != 0) {
        std::string z = std::to_string(x%3);
        s = z + s;
        x=x/3;
    }
    return s;
}
int main() {
    int a, c, res = 0, flag = 0;
    std::cin >> a >> c;
    std::string q = tr(a), e = tr(c), k = "";
    while (q.size() < e.size()) {
        q = "0" + q;
    }
    while (e.size() < q.size()) {
        e = "0" + e;
    }
    for (int j = 0; j < q.size(); j++) {
        int x = q[j], y = e[j];
        for (int i = 0; i < 3; i++) {
            if ((x-48 + i) % 3 == y-48) {              
                std::string p = std::to_string(i);
                if (k.size() != 0) {
                    k += p;
                    break;
                }
                else {
                    if (p != "0") {
                        k += p;
                        break;
                    }
                }
            }
        }
    }
    for (int j = k.size(); j > 0; j--) {
        int d = int(k[k.size() - j]-48);
        res += d * pow(3, j-1);
    }
    std::cout << res;
    return 0;
}
