#include <iostream>
int main() {
    int n, x = 0, y = 0, k = 0, flag=0,pos=0;
    std::string s;
    std::cin >> n;
    std::cin >> s;
    for (int i = 0; i < n; i++) {
        char t = s[i];
        if (flag == 1) {
            if (t == 'R') {
                x++;
                if (pos == 1 && x > y) {
                    k++;
                    pos = 0;
                }
            }
            else {
                y++;
                if (pos == 0 && x < y) {
                    k++;
                    pos = 1;
                }
            }
        }
        if (t == 'U' && flag!=1) {
            y++;
            if (y > x) {
                pos = 1;
            }
        }
        else if (t == 'R' && flag != 1) {
            x++;
            if (x > y) {
                pos = 0;
            }
        }
        if (x == y) {
            flag = 1;
        }
        else {
            flag = 0;
        }
    }
    std::cout << k;
    return 0;
}