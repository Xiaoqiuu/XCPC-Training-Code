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
Date: 2025-07-15 12:37:04
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
// wida's template : https://github.com/hh2048/XCPC/blob/main/
template <class T> struct Segt_ {
    struct node {
        int l, r;
        T w, add, mul = 1; // 注意初始赋值
    };
    vector<T> w;
    vector<node> t;

    Segt_(int n) {
        w.resize(n + 1);
        t.resize((n << 2) + 1);
        build(1, n);
    }
    Segt_(vector<int> in) {
        int n = in.size() - 1;
        w.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            w[i] = in[i];
        }
        t.resize((n << 2) + 1);
        build(1, n);
    }
    void pushdown(node &p, T add, T mul) { // 在此更新下递函数
        p.w = p.w * mul + (p.r - p.l + 1) * add;
        p.add = p.add * mul + add;
        p.mul *= mul;
    }
    void pushup(node &p, node &l, node &r) { // 在此更新上传函数
        p.w = l.w + r.w;
    }
#define GL (k << 1)
#define GR (k << 1 | 1)
    void pushdown(int k) { // 不需要动
        pushdown(t[GL], t[k].add, t[k].mul);
        pushdown(t[GR], t[k].add, t[k].mul);
        t[k].add = 0, t[k].mul = 1;
    }
    void pushup(int k) { // 不需要动
        pushup(t[k], t[GL], t[GR]);
    }
    void build(int l, int r, int k = 1) {
        if (l == r) {
            t[k] = {l, r, w[l]};
            return;
        }
        t[k] = {l, r};
        int mid = (l + r) / 2;
        build(l, mid, GL);
        build(mid + 1, r, GR);
        pushup(k);
    }
    void modify(int l, int r, T val, int k = 1) { // 区间修改
        if (l <= t[k].l && t[k].r <= r) {
            t[k].w += (t[k].r - t[k].l + 1) * val;
            t[k].add += val;
            return;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        if (l <= mid) modify(l, r, val, GL);
        if (mid < r) modify(l, r, val, GR);
        pushup(k);
    }
    void modify2(int l, int r, T val, int k = 1) { // 区间修改
        if (l <= t[k].l && t[k].r <= r) {
            t[k].w *= val;
            t[k].add *= val;
            t[k].mul *= val;
            return;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        if (l <= mid) modify2(l, r, val, GL);
        if (mid < r) modify2(l, r, val, GR);
        pushup(k);
    }
    T ask(int l, int r, int k = 1) { // 区间询问，不合并
        if (l <= t[k].l && t[k].r <= r) {
            return t[k].w;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        T ans = 0;
        if (l <= mid) ans += ask(l, r, GL);
        if (mid < r) ans += ask(l, r, GR);
        return ans;
    }
    int Kth(int k , int p = 1) {
        if (t[p].l == t[p].r) return t[p].l;
        pushdown(p);
        int lc = t[p<<1].w;
        if (k <= lc) {
            return Kth(k, GL);
        } else {
            return Kth(k - lc, GR);
        }
    }
    void debug(int k = 1) {
        cout << "[" << t[k].l << ", " << t[k].r << "]: ";
        cout << "w = " << t[k].w << ", ";
        cout << "add = " << t[k].add << ", ";
        cout << "mul = " << t[k].mul << ", ";
        cout << endl;
        if (t[k].l == t[k].r) return;
        debug(GL), debug(GR);
    }
#undef GL
#undef GR
};

vll a, cur;

void solve() {
    int n, q; cin >> n >> q;
    a.resize(n);
    cur.resize(n);
    
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        cur[i] = a[i];
    }
    ll ans = 0;
    vector<pair<int, ll>> up(q);
    vll xs = a;
    
    for (int i = 0; i < q; ++ i) {
        int p;
        ll v;
        cin >> p >> v;
        -- p;
        up[i] = { p, v };
        cur[p] += v;
        xs.pb((cur[p]));
    }
    // lisan
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    int M = xs.size();
    
//     cin.clear();
//     cin.seekg(0, ios_base::beg);
//     int TT; cin >> TT;
//     for (int __ = 0; __ < TT; ++ __) {
//         if (__ == ())
//     }
    Segt_<ll> st(M);
    vi pos(n);
    for (int i = 0; i < n; ++ i) {
        int id = int(lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin()) + 1;
        pos[i] = id;
        st.modify(id, id, 1);
        cur[i] = a[i];
    }
    int k = (n + 1) / 2;
    for (int i = 0; i < q; ++ i) {
        int p = up[i].fi;
        ll v = up[i].se;
        st.modify(pos[p], pos[p], -1);
        cur[p] += v;
        int id = int(lower_bound(xs.begin(), xs.end(), cur[p]) - xs.begin()) + 1;
        pos[p] = id;
        st.modify(id, id, 1);
        // 二分
//         int l = 1, r = M;
//         int want = k;
//         while (l < r) {
//             int m = (l + r) >> 1;
            
//             ll cntL = st.ask(1, m);
//             if (cntL >= want) {
//                 r = m;
//             } else {
//                 want -= cntL;
//                 l = m + 1;
//             }
//         }
        int bpos = st.Kth(k);
        ans = int(st.ask(1, bpos));

//         int l = 1, r = M;
//         int rpos = 0;
//         while (l <= r) {
//             int m = (l + r) >> 1;
//             if (st.ask(1, m) <= k) {
//                 rpos = m;
//                 l = m + 1;
//             } else {
//                 l = m - 1;
//             }
//         }
//         ans = int(st.ask(1, rpos));
        cout << ans << endl;
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
