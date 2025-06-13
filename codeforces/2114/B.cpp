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
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
#define akitama return 0
/*
Author: Akitama
Date: 2025-05-26 22:43:21
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

void solve() {
    int n, k; cin >> n >> k;
    string s;
    cin >> s;

    int cnt0 = count(s.begin(), s.end(), '0');
    int cnt1 = n - cnt0;
    int m = n / 2 - k;

    if (k > n / 2 || m < 0) {
        cout << "No\n";
        return;
    }
    if (cnt0 >= m && cnt1 >= m) {
        int res = cnt0 - m;
        if(res % 2 == 0) {
            int x = res / 2;
            if (x >= 0 && x <= k) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
