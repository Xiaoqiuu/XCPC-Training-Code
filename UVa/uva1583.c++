#include <iostream>
#include <vector>
using namespace std;

constexpr int N = 1e5 + 7;
vector<int> table(N + 1, 0);

void init() {
	for (int i = 1; i <= N; ++ i) {
		int x = i, res = i;
		while (x > 0) {
			res += x % 10; x /= 10;
		}
		if (table[res] == 0 || i < table[res]) {
			table[res] = i;
		}
	}
}

signed main() {
	init();
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		cout << table[n] << endl;
	}
}