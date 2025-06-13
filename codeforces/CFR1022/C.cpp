#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <utility>
#include <climits>
#include <bitset>

using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
#define int long long
//#define ul unsigned long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define akitama return 0
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) (x&-(x))

const int MOD = 998244353;
const int N = 100005;

// 10 9 8 7 6 5 4 3 2 1

void solve1() {
    int n; cin >> n;
    vll a(n);
    for (auto &i : a) cin >> i;
    ll ans = 0;
    for (int i = 0; i < n;) {
        int j = i;
        while (j + 1 < n && a[j + 1] == a[i]) {
            ++j;
        }
        ll v = a[i];
        bool f = (i==0)||(a[i-1]<v);
        bool ff = (j==n-1)||(a[j+1]<v);
        if(f && ff) {
            ++ans;
        }
        i = j + 1;
    }
    cout << ans << endl;
    return;
}

void solve() {
    int n; cin >> n;
    vector<pii> a(n);
    // for (auto &i : a) cin >> i;
    
    for (int i = 0; i < n; ++ i) {
        cin >> a[i].fi;
        a[i].se = -i;
    }
    sort(a.begin(), a.end(), [](const pii& x, const pii& y){
        if (x.fi != y.fi) return x.fi > y.fi;
        return x.se > y.se;
    });
    vi pos;
    for (const auto &p : a) {
        pos.pb(-p.se);
    }
    vi cnt;
    for (auto& i : pos) {
        auto it = lower_bound(cnt.begin(), cnt.end(), i);
        if (it == cnt.end()) {
            cnt.pb(i);
        } else {
            *it = i;
        }
    }
    cout << cnt.size() << endl;
    return;
}

signed main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _;cin >> _;
    //int _ = 1;
    while (_) {
        solve1();
        _--;
    }
    akitama;
}