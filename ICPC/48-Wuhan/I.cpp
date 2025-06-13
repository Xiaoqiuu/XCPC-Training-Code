#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <utility>

using namespace std;

#define akitama return 0
#define ll long long
#define ull unsigned long long int
#define vi vector<int>
#define vll vector<ll>

void solve() {
    string s; cin >> s;
    int ans = 0;
    bool flag = false;
    for (int i = 0; i < s.size(); ++ i) {
        if (s[i] == '1') {
            flag = true;
        }
        if (flag == true && s[i] == '0') {
            ans ++;
            flag = false;
        }
    }
    cout << ans << endl;
}



signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    //cin >> _;
    while (_) {
        solve();
        _--;
    }
    akitama;
}