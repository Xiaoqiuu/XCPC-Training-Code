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
Date: 2025-06-08 16:10:43
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

vi a;

inline int _gcd(int a, int b)
{
    register int az=__builtin_ctz(a),bz=__builtin_ctz(b),z=az>bz?bz:az,diff;
    b>>=bz;
    while(a)
    {
        a>>=az;
        diff=b-a;
        az=__builtin_ctz(diff);
        if(a<b)b=a;
        a=diff<0?-diff:diff;
    }
    return b<<z;
}

void solve() {
    int n; cin >> n;
    a.resize(n, 0);
    for (int &i : a) cin >> i;
    int num = a[0];
    for (int i = 0; i < n; ++ i) {
        num = _gcd(a[i], num);
        if (num == 1) break;
    }
    bool f = 1;
    for (int i = 0; i < n; ++ i) {
        if (a[i] != num) { f = 0; break; }
    }

    if (f) { cout << "NO" << endl; return; }
    else {
        cout << "YES\n";
    }
    vi ans(n, 2);
    for (int i = 0; i < n; ++ i) {
        if (a[i] != num) {
            ans[i] = 1;
            break;
        }
    }
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
