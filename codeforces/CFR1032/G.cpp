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
#define i64 long long int
/*

*/
#define akitama return 0
/*
Author: Akitama
Date: 2025-07-23 00:56:17
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

struct BIT {
    vector<i64> a, b;
    int n;
    BIT(int n) : n(n), a(n + 5), b(n + 5) {}
    void rangeAdd(int l, int r, i64 val) { // 区间修改
        auto add = [&](int pos, i64 val) {
            for (int i = pos; i <= n; i += i & -i) {
                a[i] += val;
                b[i] += pos * val;
            }
        };
        add(l, val), add(r + 1, -val);
    }
    i64 rangeSum(int l, int r) { // 区间和查询
        auto sum = [&](int x) {
            i64 ans = 0;
            for (int i = x; i; i -= i & -i) {
                if (i <= n)
                    ans += (x + 1) * a[i] - b[i];
            }
            return ans;
        };
        return sum(r) - sum(l - 1);

    }
 };

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int m = 2 * n + 20;
    BIT f(m);
    int zero = n + 10;
    const int BIT_MIN = 1, BIT_MAX = m;
    ll res = 0, r1 = 0;
    for (char c : s) {
        if (c == '0') {
            r1 += f.rangeSum(zero, m - 1);
            r1++;
            zero = max(zero - 1, 1);
            f.rangeAdd(zero + 1, zero + 1, 1);
        } else {
            r1 += f.rangeSum(1, zero);
            r1 += 1;
            zero += 1;
            f.rangeAdd(zero - 1, zero - 1, 1);
        } res += r1;
    }
    cout << res << endl;
    // for (int i = 0; i < n; ++ i) {

    // }
    // 0110
    // 011
    // 01
    // 0

    // C0 - C1
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
