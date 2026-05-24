/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-05-23 21:11:14
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-05-23 21:17:16
 * @FilePath: /workspace/atcoder/abc459/D.cpp
 * @Description: XCPC | 408 | Unity | Agents
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

#define akitama return 0

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

void solve() {
    string s; cin >> s;
    map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }
    int len = s.size();
    int maxc = 0;
    for (auto p : mp) {
        maxc = max(maxc, p.se);
    }
    if (maxc > (len + 1) / 2) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    vector<pair<int, char>> v;
    for (auto p : mp) {
        v.pb({p.se, p.fi});
    }
    sort(v.rbegin(), v.rend());
    vector<char> ans(len);
    int pos = 0;
    for (auto p : v) {
        int cnt = p.fi;
        char ch = p.se;
        while (cnt--) {
            ans[pos] = ch;
            pos += 2;
            if (pos >= len) {
                pos = 1;
            }
        }
    }
    for (auto c : ans) cout << c;
    cout << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);

    int _ = 1; cin >> _;
    while (_--) {
        solve();
    }

    akitama;
}