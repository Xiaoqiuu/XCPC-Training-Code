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
Date: 2026-02-12 23:10:00
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

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    // 10001
    // 10000001
    // 100000100
    // 100001
    // 1000000 // 
    // 100000 // 
    // 10000 // 1
    // 1000 // 1
    // 100 // 1
    // 10
    bool f = 1;
    if (s[0] == '0') f = 1;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); ++ i) {
        if (s[i] == '0') cnt++;
        else {
            if (!f) {
                ++ans;
                ans += cnt / 3;
                cnt = 0;
            } else {
                ++ans;
                ans += (cnt + 1) / 3;
                cnt = 0, f = 0;
            }
        }
    }
    if (f) ans +=  (cnt + 2) / 3;
    else ans += (cnt + 1) / 3;
    cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}