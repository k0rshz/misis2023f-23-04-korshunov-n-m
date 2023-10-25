#include <iostream>
#include <vector>
int main() {
	int m;
	std::cin >> m;
	for (int j = 0; j < m; j++) {
		std::vector <int> b;
		int n, k=0, otv=0, flag=0;
		char c;
		std::string s;
		std::cin >> n >> c >> s;
		s = s + s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == c) {
				flag = 1;
				//while (s[a] != 'g') {
					//k++;
					//a++;
				//}
			}
			if (flag == 1 && s[i] != 'g') {
				k++;
			}
			if (s[i] == 'g') {
				b.push_back(k);
				k = 0;
				flag = 0;
			}
		}
		for (int i = 0; i < b.size(); i++) {
			otv = std::max(otv, b[i]);
		}
		std::cout << otv << "\n";
	}
	return 0;
}