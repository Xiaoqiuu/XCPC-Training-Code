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
//#define ll long long
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

void solve() {
    ll n, x;
    cin >> n >> x;
    ll s0 = 0;
    int c[31] = {0};
    for (int j = 0; j < 31; ++ j) {
        if (x >> j & 1) {
            c[j] = 1;
            s0++;
        }
    }
    if (s0 >= n) {
        cout << x << endl;
        return;
    }
    ll d = n - s0;
    ll t = (d+1)/2;
    ll tot = 0;
    ll sv[31];
    for (int j = 0; j < 31;++j) {
        sv[j] = (n - c[j]) / 2;
        tot += sv[j];
    }
    if (tot < t) {
        cout << "-1\n";
        return;
    }
    ll nd = t, sum = 0;
    for (int j = 0; j < 31 && nd > 0; ++ j) {
        ll take = min(sv[j], nd);
        sum += take * (1LL << j);
        nd -= take;
    }
    cout << (x + 2 * sum) << endl;
    return;
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