
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::sort;
using std::string;
using std::endl;

using ll = long long int;

#define akitama return 0
#define vi vector<int>
#define vll vector<ll>

int a, b, c;

signed main() {
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		int k; cin >> k;
		string s; cin >> s;

		a = 0, b = 0, c = 0;
		
//		int tp0 = 0, tp1 = 0;
		for (char ch : s) {
			if (ch == '0') a++;
			else if (ch == '1') b++;
			else ++ c;
		}
		std::string ans(n, '?');
		
		for (int i = 1; i <= n; ++ i) {
			int l = std::max(0, i - (n - b - c));
			int r = std::min(c, i - a - 1);
//			if (i <= tp0) ans[i - 1] = '-';
//			else if (i >= n + 1 - tp1) ans[i - 1] = '-';
			if (l > r) ans[i - 1] = '-';
			else if (i >= 1 + a + c && i <= n - b - c) ans[i - 1] = '+';
			else ans[i - 1] = '?';
		}
//		cout << ans << "\n--------\n";
//		for (char c : s) {
//			if (c == '2') {
//				if (l < r - 2) {
//					l++, r--;
//				} else break;
//			}
//		}
		
//		for (int i = l + 1; i <= r - 1; ++ i) {
//			ans[i - 1] = '+';
//		}
		
		cout << ans << endl;
	}
}