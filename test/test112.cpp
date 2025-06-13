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
Date: 2025-06-04 18:12:31
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

void solve() {
    string s; cin >> s;
    int len = s.size();
    // %
    if (s[len-1] == '%') {
        if (s== "0%") { cout << "0%\n"; return; }
        bool f = 0;
        for (int i = len - 2; i >= 0; -- i) {
            if (s[i]== '0' && f == 0) continue;
            else {
                f = 1;
                cout << s[i];
            }
        }
        cout << "%" << endl;
        return;
    }
    int status = -1;
    int slp = 0;
    // . 1
    // / 2
    //default
    for (int i = len - 1; i >= 0; -- i) {
        if (s[i] == '.') { status = 1, slp = i; break; }
        else if (s[i] == '/') { status = 2, slp = i; break; }
    }
    bool f = 0;
    switch (status) {
        case 1: 
            {for (int i = slp - 1; i >= 0; -- i) {
                if (s[i] == '0' && f == 0) continue;
                else { f = 1; cout << s[i]; };
            }
            cout << ".";
            f = 0;
            string ans = "";
            for (int i = slp + 1; i < len; ++ i) {
                if (s[i] == '0' && f == 0) continue;
                else { f = 1; ans += s[i]; }
            }
            reverse(ans.begin(), ans.end());
            cout << ans;
            break;}
        case 2:
            {string ans1 = "";
            f = 0;
            for (int i = slp - 1; i > -1; -- i) {
                if (s[i] == '0' && !f) continue;
                else { f = 1; cout << s[i]; }
            }
            f = 0;
            cout << "/";
            for (int i = slp + 1; i < len; ++ i) {
                if (s[i] == '0' && f == 0) continue;
                else { f = 1; ans1 += s[i]; }
            }
            reverse(ans1.begin(), ans1.end());
            cout << ans1;
            break;}
        default: {
            f = 0;
            for (int i = len - 1; i > -1; i --) {
                if (s[i] == '0' && f == 0) continue;
                else {
                    f = 1;
                    cout << s[i];
                }
            }
        }
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
