#include <bits/stdc++.h>
using namespace std;

#define akitama return 0
using ll = long long int;
#define i64 long long int
#define pb push_back

using u64 = uint64_t;
using u128 = __uint128_t;
struct Montgomery {
u64 m, m2, im, l1, l2;
Montgomery() {}
Montgomery(u64 m) : m(m) {
l1 = -(u64)m % m, l2 = -(u128)m % m;
m2 = m << 1, im = m;
for (int i = 0; i < 5; i++) {
im *= 2 - m * im;
}
}
inline u64 operator()(i64 a, i64 b) const {
u128 c = (u128)a * b;
return u64(c >> 64) + m - u64((u64)c * im * (u128)m >> 64);
}
inline u64 reduce(u64 a) const {
a = m - u64(a * im * (u128)m >> 64);
return a >= m ? a - m : a;
}
inline u64 trans(i64 a) const {
return (*this)(a, l2);
}
inline u64 mul(i64 a, i64 b) const {
u64 r = (*this)(trans(a), trans(b));
return reduce(r);
}
u64 pow(u64 a, u64 n) {
u64 r = l1;
a = trans(a);
for (; n; n >>= 1, a = (*this)(a, a)) {
if (n & 1) r = (*this)(r, a);
}
return reduce(r);
}
};
bool isprime(i64 n) {
if (n < 2 || n % 6 % 4 != 1) {
return (n | 1) == 3;
}
u64 s = __builtin_ctzll(n - 1), d = n >> s;
Montgomery M(n);
for (i64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
u64 p = M.pow(a, d), i = s;
while (p != 1 && p != n - 1 && a % n && i--) {
p = M.mul(p, p);
}
if (p != n - 1 && i != s) return false;
}
return true;
}
void solve() {
    int n, m;cin >> n >> m;
    vector<string> g(n);
    for (auto &i : g) cin >> i;
    bool check = 1;
    for (auto& r : g) {
        check &= (r.find('1') == string::npos);
    }
    if (check) { cout << "YES\n", return; }
    vector<bool> r1(n);
    for (int i = 0; i< n; ++ i) {
        r1[i] = (g[i].find('0')==string::npos);
    }
    int cr = count(r1.begin(), r1.end(), 1);
    if (cr >= 2) {
        bool f = 1;
        for (int i = 0; i < n ; ++ i) {
            if (!r1[i]) {
                f &= (g[i].find('1') == string::npos);
            }
        }
        if (f) { cout << "YES\n"; return; }
    }

    vector<bool> c1(m, 1);
    for (int j = 0; j < m; ++ j)
    for (int i = 0; i < n; ++ i) {
        if (g[i][j] != '1') c1[j] = 0;
    }
    int cc = count(c1.begin(), c1.end(), 1);
    if (cc >= 2) {
        bool f = 1;j
        for (int j = 0; j < m ; ++ j) {
            if (!c1[j]) {
                for (int i = 0; i < n;++ i)
                f &= (g[i][j] == '0');    
            }
        }
        if (f) { cout << "YES\n"; return; }
    }

    bool ff = 0;
    for (int i = 0; i < n; ++ i) {
        int c0 = 0, p = -1;
        for (int j = 0; j < m; ++ j) {
            if (g[i][j] == '0') {
                c0++;
                p = j;
            }
        }
        if (c0 != 1) continue;
        bool fff = 1;
        for (int k = 0; j < n; ++ k) {
            if (k == i) continue;
            if (g[k][p] != '1') fff = 0;
            for (int j = 0; j < m; ++ j) {
                if (j != p && g[k][j] != '0') fff = 0;
            }
            if (!fff) break;
        }
        if (fff) { ff = 1, break; }
        
    }
    cout << (ff? "YES" : "NO") << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ ;cin >> _;
    while (_) {
        solve();
        _--;
    }
    akitama;
}