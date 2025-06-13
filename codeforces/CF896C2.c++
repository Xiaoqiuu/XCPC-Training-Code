#include <bits/stdc++.h>
using namespace std;

#define akitama return 0
#define ll long long
#define int long long

ll seed, vmax;

ll rnd() {
    ll ret = seed;
    seed = (seed * 7 + 13) % 1000000007LL;
    return ret;
}


int qpow(int a, int b, int MOD) {
    int res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

struct node {
    int l, r;
    mutable ll v;
    node(int L, int R = -1, ll V = 0) : l(L), r(R), v(V) {}
    bool operator<(const node& o) const {
        return l < o.l;
    }
};

set<node> s;


set<node>::iterator split(int pos) {
    auto it = s.lower_bound(node(pos));
    if (it != s.end() && it->l == pos) return it;
    --it;
    if (pos > it->r) return s.end();
    int L = it->l, R = it->r;
    ll V = it->v;
    s.erase(it);
    s.insert(node(L, pos - 1, V));
    return s.insert(node(pos, R, V)).first;
}


void add(int l, int r, ll val) {
    auto itr = split(r + 1), itl = split(l);
    for (; itl != itr; ++itl) itl->v += val;
}

void assign(int l, int r, ll val) {
    auto itr = split(r + 1), itl = split(l);
    s.erase(itl, itr);
    s.insert(node(l, r, val));
}


ll kth_smallest(int l, int r, int k) {
    auto itr = split(r + 1), itl = split(l);
    vector<pair<ll, int>> vp;
    for (; itl != itr; ++itl) {
        vp.emplace_back(itl->v, itl->r - itl->l + 1);
    }
    sort(vp.begin(), vp.end());
    for (auto [val, len] : vp) {
        k -= len;
        if (k <= 0) return val;
    }
    return -1;
}


ll sum(int l, int r, int ex, int mod) {
    auto itr = split(r + 1), itl = split(l);
    ll res = 0;
    for (; itl != itr; ++itl) {
        res = (res + (ll)(itl->r - itl->l + 1) * qpow(itl->v, ex, mod)) % mod;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m >> seed >> vmax;
    s.clear();

    for (int i = 1; i <= n; ++i) {
        ll val = (rnd() % vmax) + 1;
        s.insert(node(i, i, val));
    }

    for (int i = 1; i <= m; ++i) {
        int op = ((rnd() % 4) + 1);
        int l = ((rnd() % n) + 1);
        int r = ((rnd() % n) + 1);
        if (l > r) swap(l, r);

        int x = 0, y = 0;
        if (op == 3) x = ((rnd() % (r - l + 1)) + 1);
        else x = ((rnd() % vmax) + 1);

        if (op == 4) y = ((rnd() % vmax) + 1);

        if (op == 1) add(l, r, x);
        else if (op == 2) assign(l, r, x);
        else if (op == 3) cout << kth_smallest(l, r, x) << '\n';
        else cout << sum(l, r, x, y) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    akitama;
}
