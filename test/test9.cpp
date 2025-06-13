//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int t;cin >> t;
	while (t--) {
	solve();
	}
end:
	return 0;
}

void expection(int e) {
	switch(e) {
	case 1: cout << "Input invaild ! Wanna retry? y/n: ";\
			char ch;cin >> ch;if(ch == 'Y' || ch == 'y') solve(); else if(ch == 'N' || ch == 'n') goto end;\
			break;
	case 2: cout << "System error" << endl;goto end;break;
	}
}

void solve() {
	cout << "Input the data:" << endl;
	int n, m;cin >> n >> m;
	if(n < m) expection(1);
	long long a[n];
	for (int i = 0;i < n;++ i) {
		cin >> a[i];
	}
	long long ans = 0;
	for(int i = 0;i < m;++ i) {
		ans += a[i];
	}
	cout << "answer is : " << ans << endl;
}