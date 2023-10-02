#include <iostream>
#include <set>
int main() {
    std::set <int> a;
    int b;
    std::cin >> b;
    for (int i = 0; i < b; i++) {
        int s;
        std::cin >> s;
        a.insert(s);
    }
    std::cout << a.size()<<"\n";
    for (auto now: a) {
        std::cout << now<<" ";
    }
    return 0;
}
