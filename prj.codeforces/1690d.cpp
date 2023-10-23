#include <iostream>
int main() {
	int m;
	std::cin >> m;
	for (int g = 0; g < m; g++) {
		int n, k, c=2172389, w=0, b=0, ch=2178217, f=0;
		std::cin >> n >> k;
		std::string s;
		std::cin >> s;
		for (int j = 0; j < k; j++) {
			if (s[j] == 'B') {
				b++;
				f++;
				if (f >= k) {
					c = std::min(w, c);
				}
			}
			else {
				f++;
				w++;
				if (f >= k) {
					c = std::min(w, c);
				}
			}
		}
		for (int i = 1; i <= s.size() - k; i++) {
			if (s[i - 1] == 'B') {
				if (b != 0) {
					b--;
				}
			}
			else {
				if (w != 0) {
					w--;
				}
			}
			if (s[i + k - 1] == 'B') {
				b++;
			}
			else {
				w++;
			}
			if (b+w >= k) {
				c = std::min(w, c);
			}
		}
		std::cout << c << "\n";
	}
	return 0;
}