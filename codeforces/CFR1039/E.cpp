#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cstring>
// #include <climits>
// #include <utility>
// #include <cmath>
// #include <stack>
// #include <queue>
// #include <iomanip>
// #include <numeric>
// #include <bitset>
// #include <cstdlib>
// #include <set>
// // #include <multiset>
// #include <map>
// #include <unordered_map>
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
/*

*/
#define akitama return 0
/*
Author: Akitama
Date: 2025-07-27 23:49:20
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

vi a;

void solve() {
    int k, n; cin >> n >> k;
    a.resize(n);
    for (auto &i : a) cin >> i;

    // sort(a.begin(), a.end());
    int bv = -1, bl = 0, br = 0;
    for (int i = 0; i < 2; ++ i) {
        int len = k + i;
        if (len > n) continue;
        int pos = (len + 1) / 2;
        if (len % 2 == 0) pos+=1;
        int sizeL = pos - 1;
    
        vi tmp(len);
        multiset<int> L, R;
        for (int j = 0; j < len; ++ j) {
            tmp[j] = a[j];
        }

        sort(tmp.begin(), tmp.end());

        for (int j = 0; j < sizeL; ++ j) L.insert(tmp[j]);
        for (int j = sizeL; j < len; ++ j) R.insert(tmp[j]);

        auto check = [&](int l, int r) {
            int v = *R.begin();
            // gengxin 
            if (v > bv) {
                bv = v;
                bl = l;
                br = r;
            }
        };
        check(0, len - 1);
        for (int j = len; j < n; ++ j) {
            int out = a[j - len];
            // multiset<int>::iterator it = L.find(out);
            // if (it != L.end()) L.erase(it);
            // else {
            //     it = R.find(out);
            //     R.erase(it);
            // }
            int med = *R.begin();
            if (out >= med) {
                auto it = R.find(out);
                R.erase(it);
            } else {
                auto it = L.find(out);
                L.erase(it);
            }
            int in = a[j];
            if (R.empty() || in >= *R.begin()) R.insert(in);
            else {
                L.insert(in);
            }
            while ((int)L.size() > sizeL) {
                auto it2 = prev(L.end());
                R.insert(*it2);
                L.erase(it2);
            }
            while ((int)L.size() < sizeL) {
                auto it2 = R.begin();
                L.insert(*it2);
                R.erase(it2);
            }
            check(j + 1 - len, j);
        }
    }

    // for (int i = 0; i < n; ++ i) {

    // }
    cout << bv << " " << bl + 1 << " " << br + 1 << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
