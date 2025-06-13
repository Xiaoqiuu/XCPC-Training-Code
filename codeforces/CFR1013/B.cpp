#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
using ll = long long;
//#define ll long long
#define ul unsigned long long
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define akitama return 0
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MOD = 998244353;
const int N = 100005;

void solve() {
    ll n, tar; cin >> n >> tar;
    vl a(n);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    stable_sort(a.begin(), a.end(), [](int a, int b) {
        return a < b;
    });
    ll ans = 0;
    // 2 3 3 4 5 6    for (int i = 0)
    // int j = 0;
    for (int i = n-1; i > -1; -- i) {
        if (a[i] >= tar) ans ++;
        else {
            int ei = i - 1;
            while (ei >= 0 && ll(a[ei]) * (i - ei + 1) < tar) ei--;
            if (ei >= 0 && ll(a[ei]) * (i - ei + 1) >= tar) {
                ans++;
            }
            i = ei;
        }
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _;cin >> _;
    //int _ = 1;
    while (_) {
        solve();
        _--;
    }
    akitama;
}