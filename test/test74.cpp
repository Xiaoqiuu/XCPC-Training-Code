//#include <bits/stdc++.h>
#include <iostream>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

#define ll long long int
#define akitama return 0

void solve() {
	printf("First DevC++ Testing....\n");
	ll num = __gcd(2992,25672);
	printf("The answer is : %lld\n", num);
	
	bitset<8> a(8);
	cout << a << endl;
	cout << "The number of 1 pos is : " << a.count() << endl;
	string s = a.to_string();
	cout << s << endl;
	if (a.any()) { cout << "Yes\n"; } else { cout << "No.\n"; }
	vector<ll> v = {1, 2, 3, 4, 5, 6, 7, 8};
	while (next_permutation(v.begin(), v.end()))
    {
		for (auto i : v){
			cout << i << " ";
		} 
		cout << endl;
	}
	return;
}

signed main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	int _ = 1;
//	int _; cin >> _;
	while (_) {
		solve();
		_--;
	}
	akitama;
} 