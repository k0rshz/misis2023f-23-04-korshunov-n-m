#include <iostream>
#include <string>
int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n,k,ch=0;
        std::string s,a,c;
        std::cin >> n >> s >> k;
        for (int j = 0; j < k; j++) {
            std::cin >> c;
            a += c;
        }
        int f = s.size(),r=0,q,flag=0;
        while (r == 0) {
            for (int j = 0; j < f; j++) {
                for (int g = 0; g < a.size(); g++) {
                    if (s[j] == a[g] && j != 0) {
                        //s.erase(j - 1, 1);
                        s.replace(j - 1, 1, "");
                        f--;
                        flag = 1;
                        j--;
                        break;
                    }
                }
            }
            if (flag == 0) {
                break;
            }
            ch++;
            for (int g = 0; g < f; g++) {
                for (int z = 0; z < a.size(); z++) {
                    if (s[g] == a[z]) {
                        r++;
                        q = g;
                        break;
                    }
                }
            }
            if (r == 1 && q == 0) {
                r = 1;
            }
            else {
                r = 0;
            }
        }
    std::cout << ch << "\n";
    }
    return 0;
}