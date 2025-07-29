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
Date: 2025-07-27 22:45:00
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
    string ans;
    ans.reserve(n);

    vi suf_i(n, 1), suf_d(n, 1);
    for (int i = n - 2; i >= 0; -- i) {
        if (p[i] < p[i + 1]) suf_i[i] = suf_i[i + 1] + 1;
        if (p[i] > p[i + 1]) suf_d[i] = suf_d[i + 1] + 1;
    }

    auto check = [&](int x) {
        int m = q.size();
        if (m < 4) return false;
        bool f = 1, ff = 1;
        int v0 = q[m - 4], v1 = q[m - 3], v2 = q[m - 2], v3 = q[m - 1], v4 = x;
        f &= (v0 < v1 && v1 < v2 && v2 < v3 && v3 < v4);
        ff &= (v0 > v1 && v1 > v2 && v2 > v3 && v3 > v4);
        return f || ff;
    };

    while (l <= r) {
        int x = p[l];
        int y = p[r];
        bool okl = !check(x);
        bool okr = !check(r);
        if(okl && okr) {
            int len = r - l + 1;
            if (len >= 5 && suf_i[l] >= len) {
                ans.pb('R');
                q.pb(y);
                r--;
            } else if (len >= 5 && suf_d[l] >= len) {
                ans.pb('L');
                q.pb(x);
                l++;
            } else {
                if (x < y) {
                    ans.pb('L');
                    q.pb(x);
                    l++;
                } else {
                    ans.pb('R');
                    q.pb(y);
                    r--;
                }
            }
        } else if (okl) {
            ans.pb('L');
            q.pb(x);
            l++;
        } else {
            ans.pb('R');
            q.pb(y);
            r--;
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
