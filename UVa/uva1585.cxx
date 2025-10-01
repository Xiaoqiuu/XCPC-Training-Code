#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

signed main() {
	int _; cin >> _;
	while (_--) {
		string s; cin >> s;
		int ans = 0;
		int cnt = 0;
		for (char c : s) {
			if (c == 'O') {
				cnt++;
				ans += cnt;
			} else {
				cnt = 0;
			}
 		}
		cout << ans << endl;
	}
}