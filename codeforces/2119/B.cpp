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
Date: 2025-07-05 22:51:23
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

vll a;

ll llmax(ll a, ll b) {
    return (a > b? a : b);
}

void solve() {
    // l < d < h
    int n; cin >> n;
    a.resize(n);
    ll px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    
    ll sum = 0, mx = 0;

    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        sum += a[i];
        mx = llmax(mx, a[i]);
    }
    ll x = sum - mx;
    ll l = (mx > x? mx - x : 0);
    ll h = sum;
    // ojld distance
    ll dx = qx - px;
    ll dy = qy - py;
    ll dis = dx * dx + dy * dy;
    if (dis >= l * l && dis <= h * h) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
