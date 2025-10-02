#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

signed main() {
	int _; cin >> _;
	while (_--) {
		string s; cin >> s;
		int len = s.length();
		int k = len;
		string str = "";
		for (int i = 1; i <= len; ++ i) {
			str += s[i - 1];
//			k = i;
			if (len % i) continue;
			bool f = 1;
			// hohoho
			// k = 2
			// j < 4
			for (int j = 0; j < len / i; j ++) {
				for (int x = 0; x < i; ++ x) {
//					if (str[x] == s[j + x]) continue;
//					else {
//						f = 1;
//						break;
					if (str[x] != s[i * j + x]) {
						f = 0;
						break;
					}
				}
				if (!f) break;
			}
			
			if (f) {
				k = i;
				break;
			}
			else continue;
		}
		cout << k << (_ == 0? "\n" : "\n\n");
	}
}