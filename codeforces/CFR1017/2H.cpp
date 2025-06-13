#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <set>
#include <array>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <string>
using namespace std;

#define akitama return 0
using ll = long long int;
#define ull unsigned long long int
#define vi vector<int>
#define vll vector<ll>
#define si set<int>
#define pb push_back
#define fi first
#define se second

struct Sieve {
    vector<bool> isp;
    vi primes;
    int top;
    
    Sieve(int top_ = 300300) {
        top = top_ + 1;
        isp.assign(top, true);
        isp[1] = true;
        for (int i = 2;i < top; ++ i) {
            if (isp[i]) {
                primes.push_back(i);
            }
            for (auto p : primes) {
                int x = i * p;
                if (x >= top) {
                    break;
                }
                isp[x] = false;                                                    
                if (i % p == 0) break;
            }
        }
    }
    map<int, int> factorization(int v) {
        map<int, int> res;
        for (auto p : primes) {
            if (v==1) {
                break;
            }
            if (ll(p) * p > v) {
                break;
            }
            int cnt = 0;
            while (v % p == 0) {
                cnt ++;
                v /= p;
            }
            if (cnt) {
                res[p] = cnt;
            }
        }
        if (v>1) { res[v]=1; }
        return res;
    }
    vi divisors(int v) {
        map<int, int> f = factorization(v);
        vi res;
        res.pb(1);
        for (auto [p, c] : f) {
            int t = res.size(), x = 1;
            for (int i = 0; i < c; ++ i) {
                x *= p;
                for (int j = 0; j < t; ++ j) {
                    res.pb(res[j] * x);
                }
            }
        }
        return res;
    }

    bool isPrime(int v) {
        if (v < top) {
            return isp[v];
        }
        assert(ll(top-1)*(top-1)>=v);
        for (int p : primes) {
            if (v % p == 0) {
                return false;
            }
        }
        return true;
    }
};

Sieve sieve(100100);

void solve() {
    int n, qn; cin >> n >> qn;
    vi a(n);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    vector<array<int, 3>> q(qn);
    for (int i = 0; i < qn; ++ i) {
        cin >> q[i][0] >> q[i][1] >> q[i][2];
        q[i][1]--, q[i][2]--;
    }
    vector<si> en(n);
    vector<si> lv(n);
    vi qv(qn);
    for (int i = 0; i < qn; ++ i) {
        en[q[i][1]].insert(i);
        lv[q[i][2]].insert(i);
        qv[i] = q[i][0];
    }
    vi pos(qn, -1);
    vi res(qn ,0);
    map<int, si> c;
    for (int i = 0; i < n; ++ i) {
        for (auto j : en[i]) {
            for (int div : sieve.divisors(q[j][0])) {
                if (div > 1) c[div].insert(j);
            }
            pos[j] = 1;
        }
        for (auto j : c[a[i]]) {
            if (qv[j] % a[i] == 0) {
                res[j] += ll(i - pos[j]) * qv[j];
                while (qv[j] % a[i] == 0) qv[j] /= a[i];
                pos[j] = i;
            }
        }
        c[a[i]].clear();
        for (int j : lv[i]) {
            for (int div : sieve.divisors(q[j][0])) {
                if (div > 1) c[div].erase(j);
            }
            res[j] += ll(i - pos[j]+1) *qv[j];
            pos[j] = -2;
        }
    }
    for (auto x : res) cout << x << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_) {
        solve();
        _--;
    }
    akitama;
}