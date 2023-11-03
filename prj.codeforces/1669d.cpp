#include <iostream>
int main() {
	int a;
	std::cin >> a;
	for (int g = 0; g < a; g++) {
		int n,k=0;
		std::string s;
		std::cin >> n >> s;
		for (int i = 0; i < n-1; i++) {
			if ((s[i] == 'W' && s[i + 1] == 'W') || (s[i] == 'R' && s[i + 1] == 'B') || (s[i] == 'B' && s[i + 1] == 'R')) {
				k++;
			}
		}
		if (n == 1) {
			if (s[0] == 'W') {
				std::cout << "YES" << "\n";
			}
			else {
				std::cout << "NO" << "\n";
			}
		}
		else {
			if (k >= n / 2) {
				std::cout << "YES" << "\n";
			}
			else {
				std::cout << "NO" << "\n";
			}
		}
	}
	return 0;
}