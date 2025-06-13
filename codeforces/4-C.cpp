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
Date: 2025-06-01 20:37:05
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

vi cnt(N + 7, 0);
vector<string> name(N + 7);

void solve() {
    int n; cin >> n;
    string s;
    int time = 0;
    for (int i = 1; i <= n; ++ i) {
        bool f = 0;
        cin >> s;
        for (int j = 0; j < time; ++ j) {
            if (name[j] == s) {
                cnt[j]++;
                cout << s << cnt[j] << endl;
                f = 1;
                break;
            }
        }
        if (f == false) {
            name[time] = s;
            time++;
            cout << "OK\n";
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
