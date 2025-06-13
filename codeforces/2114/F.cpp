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
#include <unordered_map>
#include <deque>
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
#define akitama return 0
/*
Author: Akitama
Date: 2025-05-27 00:08:02
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

void genDivisors(const vector<pii>& pf, int idx, ll cur, vll& divs) {
    if (idx == (int)pf.size()) {
        divs.push_back(cur);
        return;
    }
    auto [p, e] = pf[idx];
    ll val = cur;
    for (int i = 0; i <= e; ++i) {
        genDivisors(pf, idx + 1, val, divs);
        val *= p;
    }
}

int bfsDivide(ll n, int k) {
    if (n == 1) return 0;
    vector<pii> pf;
    ll m = n;
    for (int p = 2; (ll)p * p <= m; ++p) {
        if (m % p == 0) {
            int cnt = 0;
            while (m % p == 0) {
                m /= p;
                ++cnt;
            }
            pf.emplace_back(p, cnt);
        }
    }
    if (m > 1) pf.emplace_back((int)m, 1);
    vll divs;
    genDivisors(pf, 0, 1, divs);
    sort(divs.begin(), divs.end());
    int D = divs.size();
    unordered_map<ll,int> id;
    id.reserve(D*2);
    for (int i = 0; i < D; ++i) id[divs[i]] = i;
    vi dist(D, -1);
    deque<int> q;
    int start = id[n];
    dist[start] = 0;
    q.push_back(start);
    while (!q.empty()) {
        int u_i = q.front(); q.pop_front();
        ll u = divs[u_i];
        int d0 = dist[u_i];
        for (ll a : divs) {
            if (a < 2) continue;
            if (a > k) break;
            if (u % a != 0) continue;
            ll v = u / a;
            int v_i = id[v];
            if (dist[v_i] == -1) {
                dist[v_i] = d0 + 1;
                q.push_back(v_i);
            }
        }
    }
    return dist[id[1]];
}

int bfsMultiply(ll n, int k) {
    if (n == 1) return 0;
    vector<pii> pf;
    ll m = n;
    for (int p = 2; (ll)p * p <= m; ++p) {
        if (m % p == 0) {
            int cnt = 0;
            while (m % p == 0) {
                m /= p;
                ++cnt;
            }
            pf.emplace_back(p, cnt);
        }
    }
    if (m > 1) pf.emplace_back((int)m, 1);
    vll divs;
    genDivisors(pf, 0, 1, divs);
    sort(divs.begin(), divs.end());
    int D = divs.size();
    unordered_map<ll,int> id;
    id.reserve(D*2);
    for (int i = 0; i < D; ++i) id[divs[i]] = i;
    vi dist(D, -1);
    deque<int> q;
    int start = id[1];
    dist[start] = 0;
    q.push_back(start);
    while (!q.empty()) {
        int u_i = q.front(); q.pop_front();
        ll u = divs[u_i];
        int d0 = dist[u_i];
        for (ll a : divs) {
            if (a < 2) continue;
            if (a > k) break;
            ll v = u * a;
            if (v > n) break;
            if (n % v != 0) continue;
            int v_i = id[v];
            if (dist[v_i] == -1) {
                dist[v_i] = d0 + 1;
                q.pb(v_i);
            }
        }
    }
    return dist[id[n]];
}

void solve() {
    ll x, y;
    int k;
    cin >> x >> y >> k;
    if (k == 1) {
        cout << (x == y ? 0 : -1) << '\n';
        return;
    }
    ll g = __gcd(x, y);
    ll d1 = x / g;
    ll d2 = y / g;
    int ops1 = bfsDivide(d1, k);
    if (ops1 < 0) {
        cout << -1 << '\n';
        return;
    }
    int ops2 = bfsMultiply(d2, k);
    if (ops2 < 0) {
        cout << -1 << '\n';
        return;
    }
    cout << ops1 + ops2 << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}