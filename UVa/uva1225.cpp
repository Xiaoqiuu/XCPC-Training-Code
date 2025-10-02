#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


signed main() {
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		string s;
		vector<int> cnt(10, 0);
		for (int i = 1; i <= n; ++ i) {
			s += to_string(i);
		}
		for (char c : s) {
			cnt[c - '0']++;
		}
		for (int i = 0; i < 10; ++ i) {
			cout << cnt[i] << (i != 9? " " : "\n");
		}
	}
}