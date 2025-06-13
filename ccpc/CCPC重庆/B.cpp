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
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
#define akitama return 0
/*
Author: Akitama
Date: 2025-05-22 14:44:23
Description: Contest Template
*/

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;

struct SegmentTree {
    struct Node {
        int l, r;
        long long min_val;
        long long lazy;
    };
    
    vector<Node> tree;
    
    void build(int u, int l, int r) {
        tree[u] = {l, r, LLONG_MAX, LLONG_MAX};
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }
    
    void push_down(int u) {
        if (tree[u].lazy != LLONG_MAX) {
            tree[u << 1].min_val = min(tree[u << 1].min_val, tree[u].lazy);
            tree[u << 1].lazy = min(tree[u << 1].lazy, tree[u].lazy);
            tree[u << 1 | 1].min_val = min(tree[u << 1 | 1].min_val, tree[u].lazy);
            tree[u << 1 | 1].lazy = min(tree[u << 1 | 1].lazy, tree[u].lazy);
            tree[u].lazy = LLONG_MAX;
        }
    }
    
    void update(int u, int l, int r, long long val) {
        if (tree[u].l >= l && tree[u].r <= r) {
            tree[u].min_val = min(tree[u].min_val, val);
            tree[u].lazy = min(tree[u].lazy, val);
            return;
        }
        push_down(u);
        int mid = (tree[u].l + tree[u].r) >> 1;
        if (l <= mid) update(u << 1, l, r, val);
        if (r > mid) update(u << 1 | 1, l, r, val);
        tree[u].min_val = min(tree[u << 1].min_val, tree[u << 1 | 1].min_val);
    }
    
    long long query(int u, int l, int r) {
        if (tree[u].l >= l && tree[u].r <= r) {
            return tree[u].min_val;
        }
        push_down(u);
        int mid = (tree[u].l + tree[u].r) >> 1;
        long long res = LLONG_MAX;
        if (l <= mid) res = min(res, query(u << 1, l, r));
        if (r > mid) res = min(res, query(u << 1 | 1, l, r));
        return res;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, ll>> trains(m);
    vi points = {1, n};
    
    for (int i = 0; i < m; ++i) {
        int l, r; ll c;
        cin >> l >> r >> c;
        trains[i] = {l, r, c};
        points.pb(l);
        points.pb(r);
    }
    
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    
    SegmentTree st;
    st.tree.resize(4 * points.size());
    st.build(1, 0, points.size() - 1);
    
    for (auto &train : trains) {
        int l = lower_bound(points.begin(), points.end(), get<0>(train)) - points.begin();
        int r = lower_bound(points.begin(), points.end(), get<1>(train)) - points.begin();
        if (l <= r) {
            st.update(1, l, r, get<2>(train));
        }
    }
    
    int x = lower_bound(points.begin(), points.end(), 1) - points.begin();
    int y = lower_bound(points.begin(), points.end(), n) - points.begin();
    cout << st.query(1, x, y) << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}