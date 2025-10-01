#include <iostream>
#include <vector>

using namespace std;

signed main() {
//	ios::sync_with_stdio(false);
//	int _; cin >> _;
	int n;
	int times = 1;
	while (cin >> n && n) {
		printf("Game %d:\n", times++);
		vector<int> ans(n);
		vector<int> guess(n);
		for (auto &i : ans) cin >> i;
		while (1) {
			int num1 = 0, num2 = 0;
//			for (auto &i : guess) cin >> i;
			for (int i = 0; i < n; ++ i) {
				cin >> guess[i];
				if (guess[i] == ans[i]) num1++;
			}
			if (guess[0] == 0) break;
			for (int d = 1; d < 10; ++ d) {
				int d1 = 0, d2 = 0;
				for (int i = 0; i < n; ++ i) {
					if (d == guess[i]) d2++;
					if (d == ans[i]) d1++;
				}
				if (d2 > d1) num2 = num2 + d1;
				else num2 = num2 + d2;
			}
			printf("    (%d,%d)\n", num1, num2 - num1);
		}
	}
}