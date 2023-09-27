#include <iostream>
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int a,num,ost;
        std::string s = "";
        std::cin >> a;
        num = a / 2;
        ost = a % 2;
        for (int j = 0; j < num; j++) {
            if (ost == 1) {
                s += "7";
                ost -= 1;
            }
            else {
                s += "1";
            }
        }
        std::cout << s << "\n";
    }
    return 0;
}