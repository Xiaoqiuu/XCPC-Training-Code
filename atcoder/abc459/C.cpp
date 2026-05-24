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
Date: 2026-05-23 20:07:38
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
#define lowbit(x) x & -x

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 0X3f3f3f3f;

struct BIT {
    int n;
    vector<int> tre;
    BIT(int n) : n(n), tre(n + 1, 0) {}

    void add(int x, int v) {
        for (; x <= n; x += lowbit(x)) tre[x] += v;
    }

    int sum(int x) {
        if (x > n) x = n;
        int res = 0;
        for (; x > 0; x -= lowbit(x)) res += tre[x];
        return res;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vi a(n + 1, 0);
    BIT bit(q + 5);
    vi fq(q + 5, 0); 
    fq[0] = n;
    bit.add(1, n);
    int base = 0, count = n;
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            // if (a[x] == 0) count --;
            // a[x] += 1;
            // // cout << "count : " << count << endl;
            // if (count == 0) {
            //     for (int i = 1; i <= n; ++ i) {
            //         a[i] --;
            //         if (a[i] == 0) count++;
            //     }
            // }
            int o = a[x];
            if (a[x] == base) --count;
            --fq[o];
            bit.add(o + 1, -1);
            ++a[x];
            int w = a[x];
            fq[w] ++;
            bit.add(w + 1, 1);
            if (count == 0) {
                base ++;
                count = fq[base];
            }
        } else {
            // for (auto i : a) cout << i << " ";cout << endl;
            int y; cin >> y;
            // int ans = 0;
            // for (int i = 1; i <= n; ++ i) {
            //     if (a[i] >= y) ans++;
            // }
            cout << n - bit.sum(base + y) << '\n';
        }
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
