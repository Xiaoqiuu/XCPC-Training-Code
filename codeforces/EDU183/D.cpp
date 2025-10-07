//#include <iostream>
//#include <vector>
//#include <string>
////#include <unordered_map>
//#include <algorithm>
//#include <cmath>
#include <bits/stdc++.h>

//using std::cin;
//using std::cout;
//using std::vector;
//using std::sort;
//using std::string;
//using std::endl;
//using std::unordered_map;

using namespace std;
using ll = long long int;

#define akitama return 0
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>

constexpr int INF = 1e9;

int n;
ll k;
//int n;
//string s;
//int ans = 0;
signed main() {
	int _; cin >> _;
	while (_--) {
		cin >> n >> k;
		ll t = 1LL * (n - 1) * n / 2;
		ll S = t - k;
		if (S < 0 || S > t) {
			cout << "0\n";
			continue;
		}
		
		int s = (int)S;
		
		vector<vector<char>> dp(n + 1, vector<char>(s + 1, 0));
		vvi pi(n + 1, vi(s + 1, -1));
		vvi pl(n + 1, vi(s + 1, -1));
		dp[0][0] = 1;
		
		for (int i = 0; i <= n; ++ i) {
			for (int j = 0; j <= s; ++ j) {
				if (dp[i][j]) {
					for (int len = 1; i + len <= n; ++ len) {
						int add = len * (len - 1) / 2;
						if (j + add > s) continue;
						if (!dp[i + len][j + add]) {
							dp[i + len][j + add] = 1;
							pi[i + len][j + add] = i;
							pl[i + len][j + add] = len;
						}
					}
				}
			}
		}
		
		if (!dp[n][s]) {
			cout << "0\n";
			continue;
		}
		vi ans, ans1;
		int ci = n, cj = s;
		while (ci > 0) {
			int pii = pi[ci][cj], len = pl[ci][cj];
			ans.push_back(len);
			cj -= len * (len - 1) / 2;
			ci = pii;
		}
		reverse(ans.begin(), ans.end());
		
		int cur = n;
		for (int len : ans) {
			int l = cur - len + 1;
			int r = cur;
			for (int x = l; x <= r; ++ x) ans1.push_back(x);
			cur -= len;
		}
		
		for (int i = 0; i < n; ++ i) {
			if (i) cout << " ";
			cout << ans1[i];
		} cout << endl;
	}
}