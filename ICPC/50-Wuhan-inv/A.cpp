/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-04-28 20:37:46
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-04-28 20:37:52
 * @FilePath: /workspace/ICPC/50-Wuhan-inv/A.cpp
 * @Description: XCPC | 408 | Unity | Agents
 */
#include<bits/stdc++.h>
#define fuckeverything return 0;
using namespace std;
using ll = long long;
const ll mod = 998244353;
const int N = 2e5 + 3;
const ll inf = 1e18;
void solve()
{
    ll n, q, ans = 0; cin >> n >> q;
    vector<ll> a(n + 5), l(n + 5, 0 ), r(n + 5, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= q; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        if (l[x] == 0 && r[x] == 0) {
            l[x] = y;
            r[x] = z;
        }
        else {
            if (l[x] >= y && r[x] <= z) {
                continue;
            }
            if ((y >= l[x] && y <= r[x]) || (z >= l[x] && z <= r[x])) {
                l[x] = max(l[x], y);
                r[x] = min(r[x],z);
            }

            else {
                cout << -1 << '\n';
                return;
            }
        }
    }

    for (int i = 1; i <= n; i ++) {
        if (l[i] == 0) continue;
        if (a[i] >= l[i] && a[i] <= r[i]) continue;
        ll c = abs(a[i] - l[i]);
        ll cc = abs(a[i] - r[i]);
        ans += min(c, cc);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr);
    int _;
    _ = 1;
    cin >> _;
    while (_ --) solve();
    fuckeverything
}

/*
1
5 5
1000000 2000000 30000000 40000000 1000
5 400 900
5 800 850
5 800 870
5 700 810
5 800 999
 */