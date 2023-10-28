#include <iostream>
int main() {
	long long int n;
	std::cin >> n;
	if (n == 0) {
		std::cout << 0;
	}
	else {
		if ((n + 1) % 2 == 0) {
			std::cout << (n + 1) / 2;
		}
		else {
			std::cout << n + 1;
		}
	}
	return 0;
}