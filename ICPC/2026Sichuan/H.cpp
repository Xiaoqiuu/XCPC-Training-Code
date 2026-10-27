/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-10-21 20:03:07
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-10-21 20:18:01
 * @FilePath: /workspace/ICPC/2026Sichuan/H.cpp
 * @Description: XCPC | 408 | Unity | Agents
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define akitama return 0
using ll = long long int;
ll check(ll n) {
    ll cnt = 0;
    while (n) {
        if (n % 2 == 1) {
            cnt ++;
            n = n / 2;
        } else n /= 2;
    }
    return cnt;
}

// #define ll long long int
void solve() {
    int n; cin >> n;
    // vector<int> a(n);
    ll cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; ++ i) {
        // cin >> a[i];
        // 1 2 3 5 15
        // 0001 0010 0011 0101 1111
        ll x; cin >> x;
        if(check(x) % 2 == 1) cnt1 += x;
        else cnt0 += x;
    }
    cout << max(cnt1, cnt0) << endl;
    
}

signed main() {
    int _; cin >> _;
    while (_--) {
        solve();
    }
    // cout << check(3) << endl;
    akitama;
}