#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <utility>
#include <cmath>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
/*

*/
#define akitama return 0
/*
Author: Akitama
Date: 2026-02-12 22:12:48
Akitama Default Contest Template V2.0
*/

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define l(x) x << 1
#define r(x) x << 1 | 1

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 0X3f3f3f3f;

//1010101

void solve() {
    ll n; cin >> n;
    ll cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; ++ i) {
        char c; cin >> c;
        c == '1'? cnt1 ++ : cnt0 ++;
    }
    ll ans = ((n - 1) / 3 + 1 < cnt1? cnt1 : (n - 1) / 3 + 1);
    if (cnt1 > (n - 1) / 3 + 1 && cnt1 > n / 2 + 1) ans = (n - 1) / 3 + 1;
    cout << ans << endl;


    // ll ans = 0;
    // // 0000001
    // bool start = 1;
    // if (s[0] == '1') start = 0;
    // int cnt0 = 0;
    // for (int i = 0; i < (int)s.size(); ++ i) {
    //     if (i == 0 && s[i] == '0') start = 1;
    //     if (s[i] == '0') ++cnt0;
    //     else {
    //         ++ans;
    //         if (start) {
    //             cout << "cur i : " << i << " current cnt0-------: " << cnt0 << endl;
    //             ans += cnt0 / 3;
    //             cnt0 = 0;
    //             start = 0;
    //         } else {
    //             cout << "cur i : " << i << " current cnt0-------: " << cnt0 << endl;
    //             ans += cnt0 / 5;
    //             cnt0 = 0;
    //         }
    //     }
    // }
    // cout << "current cnt0-------: " << cnt0 << endl;
    // if (start) ans += ((cnt0 / 3 == 0)? 1 : 1 + (cnt0 - 1) / 3);
    // else ans += cnt0 / 3;
    // cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
