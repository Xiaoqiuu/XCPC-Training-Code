#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

#define ll long long
#define ul unsigned long long
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define akitama return 0
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"

const int MOD = 998244353;
const int N = 100005;

void solve() {
    ll n, x, k; cin >> n >> x >> k;
    string s; cin >> s;
    ll ans = 0;
    for (ll i = 0; i < n; ++ i) {
        x += (s[i] == 'L'? -1 : 1);
        k --;
        if(x == 0) break;
    }

    if(x == 0) {
        ans = 1;
        for (ll i = 0, j = 0; i < n; ++ i) {
            j += (s[i] == 'L'? -1 : 1);
            if(j == 0) {
                ans += k / (i + 1);
                break;
            }
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