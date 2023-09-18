#include <iostream>
#include <string>
int main() {
    int b;
    std::cin >> b;
    std::string a;
    std::cin >> a;
    int k=0,c=0;
    for (int i=0; i<b; i++) {
        if (a[i] == 'x') {
            k++;
        }
        else {
            k = 0;
        }
        if ((k % 3 == 0 && k != 0) || (k>3)) {
            c++;
        }
    }
    std::cout << c;
    return 0;
}