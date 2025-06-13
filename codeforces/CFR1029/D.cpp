/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-06-09 11:11:21
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-06-09 11:44:04
 * @FilePath: /workspace/codeforces/CFR1029/D.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
/*

*/
#define akitama return 0
/*
Author: Akitama
Date: 2025-06-09 11:11:33
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
    int n; cin >> n;
    a.resize(n);
    // bool f = 1;
    for (auto &i : a) {
        cin >> i;
    }
    // if (n == 2 && a[0] > a[1]) { cout << "NO\n"; return; }
    if (is_sorted(a.begin(), a.end()) == 0) {
        for (int l = 0, r = n - 1; l <= r; l ++, r --) {
            swap(a[l], a[r]);
        }
        if (is_sorted(a.begin(), a.end()) == 0) {
            cout << "NO\n";
            return;
        }
    }

    sort(a.begin(), a.end());
    if (a[0]%(n+1)!=0) { cout << "NO\n"; return; }
    int tmp = a[1] - a[0];
    for (int i = 1; i < n; ++ i) {
        if (a[i] - a[i - 1] != tmp) {
            cout << "NO\n";
            return;
        }
    }
    
    for (int i = 0; i < n; ++ i) {
        a[i] -= i * tmp;
        if (a[i] < 0) { cout << "NO\n"; return; }
        // if (i >= 1) {
        //     if (a[i] != a[i - 1]) { cout << "NO\n"; return; }
        // }
        
    }
    
    for (int i = 1; i < n; ++ i) {
        if (a[i]!=a[i-1]) {
            cout << "NO\n";
            return;
        }
    }

    
    cout << "YES\n";
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
