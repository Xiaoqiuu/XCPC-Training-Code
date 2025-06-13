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

// Quick pow

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
vector<pair<ll, int>> vp;

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

void add(int l, int r, ll val = 1) {
    split(l);
    auto itr = split(r + 1), itl = split(l);
    for (; itl != itr; ++itl) itl->v += val;
}

void assign(int l, int r, ll val = 0) {
    split(l);
    auto itr = split(r + 1), itl = split(l);
    s.erase(itl, itr);
    s.insert(node(l, r, val));
}

ll kth_smallest(int l, int r, int k, bool reversed = false){
    if (reversed) k = r - l + 2 - k;
    split(l);
    auto itr = split(r + 1), itl = split(l);
    multiset<ll> vals;
    for(; itl != itr; ++itl){
        for(int j = 0;j < itl->r - itl->l + 1;j++){
            vals.insert(itl->v);
        }
    }
    auto it = vals.begin();
    advance(it, k - 1);
    return *it;
}

// ll kth_smallest(int l, int r, int k, bool reversed = false) {
//     if (reversed) k = r - l + 2 - k;
//     split(l);
//     auto itr = split(r + 1), itl = split(l);
//     vp.clear();
//     for (; itl != itr; ++itl) {
//         vp.push_back({itl->v, itl->r - itl->l + 1});
//     }
//     sort(vp.begin(), vp.end());
//     for (auto i : vp) {
//         k -= i.second;
//         if (k <= 0) return i.first;
//     }
//     return -1;
// }

// ll mul_mod(ll a, ll b, ll mod){
//     ll res = 0;

//     while(b){
//         if(b & 1) res = (res + a) % mod;
//         a = (a * 2) % mod;
//         b >>= 1;
//     }

//     return res;
// }
// ll pc[100005][31];
// ll mod_pow(ll base, int exp, int mod) {
//     for(ll i = 1; i <= 100000; i++){
//         pc[i][0] = 1;
//         for(ll j = 1; j <= 30; j++){
//             pc[i][j] = (pc[i][j-1] * i) % mod;
//     }}
//     return pc[base][exp];
//     // ll key = base * 1000000007LL + exp;
//     // if(pc.count(key)) return pc[key];

//     // ll res = 1;
//     // while(exp){
//     //     if(exp & 1) res = (res * base) % mod;
//     //     base = (base * base) % mod;
//     //     exp >>= 1;
//     // }
//     // return pc[key] = res;
// }



ll sum(int l, int r, int ex, int mod) {
    split(l);
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
        else if (op == 3) cout << kth_smallest(l, r, x) << endl;
        else cout << sum(l, r, x, y) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    akitama;
}
