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
Date: 2025-05-31 23:07:11
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

vi b, c;

void solve() {
    int m; cin >> m;
    b.resize(m);
    for (int i = 0; i < m; ++ i) {
        cin >> b[i];
    }
    int d = b[0];
    for (int i = 1; i < m; ++ i) {
        d = __gcd(d, b[i]);
    }
    int cnt = 0;
    for (int i = 0; i < m; i ++) {
        if (b[i] == d) cnt++;
    }
    if (cnt > 0) {
        cout << (m - cnt) << endl;
        return;
    }

    c = b;
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    int mx = c.back();

    vi d_(mx + 1, -1);
    queue<int> qu;
    for (int v : c) {
        d_[v] = 0;
        qu.push(v);
    }
    while (!qu.empty()) {
        int v = qu.front();
        qu.pop();
        if (v == d) break;
        for (auto i : c) {
            int g = __gcd(v, i);
            if (d_[g] == -1) {
                d_[g] = d_[v] + 1;
                qu.push(g);
            }
        }
    }
    
    cout << d_[d] + (m - 1) << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}