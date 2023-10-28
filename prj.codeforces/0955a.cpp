#include <iostream>
int main() {
	int hh, mm, H, D, N;
	double C;
	std::cin >> hh >> mm >> H >> D >> C >> N;
	if (hh >= 20) {
		double i = 1;
		while (H - N * i > 0) {
			i++;
		}
		std::cout << i * C * 0.8;
	}
	else {
		double i = 1, a;
		while (((20 * 60 - (hh * 60 + mm)) * D + H) - N * i > 0) {
			i++;
		}
		a = i * C * 0.8;
		i = 1;
		while (H - N * i > 0) {
			i++;
		}
		std::cout << std::min(a, C * i);
	}
	return 0;
}