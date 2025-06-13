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
#define akitama return 0
/*
Author: Akitama
Date: 2025-05-31 22:42:32
Description: Contest Template
*/

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

constexpr int N = 1e5 + 7;
constexpr int MOD = 998244353;

vi p, q;
vi p1, q1;
vi p2 = {1};

void solve() {
    int n; cin >> n;
    p.resize(n, 0);
    q.resize(n, 0);
    p1.resize(n, 0);
    q1.resize(n, 0);
    vi pm(n), qm(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p1[p[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
        q1[q[i]] = i;
    }
    
    int x = p2.size();
    if (x <= n) {
        p2.resize(n + 1);
        for (int i = x; i <= n; ++i) {
            p2[i] = (p2[i - 1] * 2) % MOD;
        }
    }
    
    pm[0] = p[0], qm[0] = q[0];
    for (int i = 1; i < n; i++) {
        pm[i] = max(p[i], pm[i - 1]);
        qm[i] = max(q[i], qm[i - 1]);
    }
    
    vi res(n, 0);
    for (int i = 0; i < n; ++i) {
        int e = max(pm[i], qm[i]);
        int s;
        if (pm[i] > qm[i]) {
            int j = p1[e];
            int k = i - j;
            s = (k >= 0 && k < n) ? q[k] : -1;
        } 
        else if (qm[i] > pm[i]) {
            int k = q1[e];
            int j = i - k;
            s = (j >= 0 && j < n) ? p[j] : -1;
        } 
        else {
            int j1 = p1[e];
            int k1 = i - j1;
            int s1 = (k1 >= 0 && k1 < n) ? q[k1] : -1;
            
            int k2 = q1[e];
            int j2 = i - k2;
            int s2 = (j2 >= 0 && j2 < n) ? p[j2] : -1;
            
            s = max(s1, s2);
        }    
        res[i] = (p2[e] + (s != -1 ? p2[s] : 0)) % MOD;

    }
    
    for (int i = 0; i < n; ++ i) cout << res[i] << " ";
    cout << "\n";
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}