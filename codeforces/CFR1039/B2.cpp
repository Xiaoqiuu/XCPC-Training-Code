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
Date: 2025-07-27 23:14:26
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
    vi p(n);
    for (auto &i : p) cin >> i;
    int l = 0, r = n - 1;
    vi q;
    q.reserve(n);
    string ans;
    ans.reserve(n);
    for (int i = 0; i < n; ++ i) {
        if((i & 1) == 0) {
            if (p[l] > p[r]) {
                ans.pb('L');
                l++;
            } else {
                ans.pb('R');
                r--;
            }} else {
                if (p[l] < p[r]) {
                    ans.pb('L');
                    l++;
                } else {
                    ans.pb('R');
                    r--;
                }
            }
        }
    
    //     int xl = p[l];
    //     int xr = p[r];
    //     bool okl = 1;
    //     int sz = q.size();
    //     if (sz >= 4) {
    //         int a = q[sz - 4], b= q[sz - 3], c = q[sz - 2], d = q[sz - 1];
    //         if ((a < b && b < c && c < d && d < xl) || (a > b && b > c && c > d && d > xl)) okl = 0;
    //     }
    //     if (okl) {
    //         ans.pb('L');
    //         q.pb(xl);
    //         l++;
    //     } else {
    //         ans.pb('R');
    //         q.pb(xr);
    //         r--;
    //     }
    // }
    
    
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
