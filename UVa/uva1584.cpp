#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

signed main() {
	int _; cin >> _;
	while (_--) {
		string s; cin >> s;
		string ans[1005];
		int len = s.size();
		
//		int a = 0, g = 0, c = 0, t = 0;
		for (int k = 0; k < len; ++ k) {
//			if (c == 'a') a++;
//			else if (c == 'c') c++;
//			else if (c == 'g') g++;
//			else t++;
			for (int i = k; i < k + len; ++ i) {
				ans[k] += s[i % len];
			}
		}
		
		sort(ans, ans + len);
		cout << ans[0] << endl;
		
//		while (a--) cout << 'A';
//		while (c--) cout << 'C';
//		while (g--) cout << 'G';
//		while (t--) cout << 'T';
//		cout << endl;
	}
}