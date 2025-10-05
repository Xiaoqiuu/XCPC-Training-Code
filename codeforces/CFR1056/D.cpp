#include <bits/stdc++.h>
using namespace std;

#define akitama return 0
#define ll long long int 

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int _;
	if (!(cin >> _)) akitama;
	while (_--) {
		int n; cin >> n;
		bool f = 0;
		for (int u = 1; u <= n && !f;++ u) {
			for (int v = u + 1; v <= n; ++ v) {
				cout << u <<' ' << v << '\n' << flush;
				int x;
				if (!(cin >> x)) akitama;
				if (x == -1) akitama;
				if (x == 1) {
					f = 1;
					break;
				}
			}
		}
//	akitama_qwq:
//		;
	}
	akitama;
}