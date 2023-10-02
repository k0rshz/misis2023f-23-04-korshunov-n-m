#include <iostream>
//#include <vector>
int main() {
    int n;
    std::cin >> n;
    for (int g = 0; g < n; g++) {
        int k = 0;
        //std::vector <std::vector <int>> a;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                char s;
                std::cin >> s;
                if (s == 'X') {
                    if (i == 0 || i == 9 || j == 0 || j == 9) {
                        k++;
                    }
                    else if (j == 1 || j == 8 || i == 1 || i == 8) {
                        k += 2;
                    }
                    else if (i == 2 || i == 7 || j == 2 || j == 7) {
                        k += 3;
                    }
                    else if (i == 3 || i == 6 || j == 3 || j == 6) {
                        k += 4;
                    }
                    else {
                        k += 5;
                    }
                }
            }
        }
        std::cout << k << "\n";
    }
    return 0;
}
