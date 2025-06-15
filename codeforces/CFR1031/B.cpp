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
Date: 2025-06-15 17:18:19
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

bool check(ll len, ll t) {
    return len == 0 || len % t == 0;
}

void solve() {
    ll w, h, a, b; cin >> w >> h >> a >> b;
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll r1 = ((x1%a)+a) % a;
    ll r2 = ((x2%a)+a) % a;
    ll s1 = ((y1%b)+b) % b;
    ll s2 = ((y2%b)+b) % b;
    bool f1 = r1 == r2 && (x1 != x2 ||s1 ==s2);
    bool f2 = s1 == s2 && (y1 != y2 || r1 == r2);
    bool f = f1 || f2;
    // if (r1 == r2 && s1 == s2) cout << "YES\n";
    // else cout << "NO\n";
    // bool f = (r1 == r2) && (s1 == s2);
    // if (f) {
    //     cout << "YES\n";
    //     return;
    // } 
    // vll xs = {0, w, x1, x1 + a, x2, x2 + a};
    // vll ys = {0, h, y1, y1 + b, y2, y2 + b};
    // sort(xs.begin(), xs.end());
    // xs.erase(unique(xs.begin(), xs.end()), xs.end());
    // sort(ys.begin(), ys.end());
    // ys.erase(unique(ys.begin(), ys.end()), ys.end());
    // bool mix = 1;
    // for (int i = 0; i + 1 < (int)xs.size()&&mix; ++ i) {
    //     for (int j = 0; j + 1 < (int)ys.size()&&mix; ++ j) {
    //         ll xl = xs[i];
    //         ll xr = xs[i+1];
    //         ll yl = ys[i];
    //         ll yr = ys[i+1];
    //         ll w0 = xr - xl, h0 = yr - yl;
    //         if (w0 == 0 || h0 == 0) continue;
    //         bool ff = (xl >= x1 && xr <= x1 + a && yl >= y1 && yr <= y1 + b) || (xl >= x2 && xr <= x2 + a && yl >= y2 && yr <= y2 + b);
    //         if(ff) continue;
    //         if (!check(w0, a) || !check(h0, b)) {
    //             mix = 0;
    //         }
    //     }
    // }
    cout << (f? "YES":"NO") << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
