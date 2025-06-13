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

const int MOD = 998244353;
const int N = 100005;

void solve() {
  int n; cin >> n;
  vi d(n+1, 0);// depth
  vi p(n+1, 0);
  for (int i = 2; i <= n; ++ i) {
    int _p; cin >> _p;
    p[i] = _p;
    d[i] = d[_p] + 1;
  }

  int max_d = *max_element(d.begin(), d.end());

  vl cnt(max_d+1, 0), tmp(max_d+1, 0);
  for (int i = 1; i <= n; ++ i) {
    cnt[d[i]]++;
  }
  if(max_d >= 1) {
    tmp[max_d] = cnt[max_d] % MOD;
  }
  for (int i = max_d - 1; i >= 1; -- i) {
    ll m = ((cnt[i] - 1) % MOD + MOD) % MOD;
    tmp[i] = ((cnt[i] + m * tmp[i+1])) % MOD;
  }
  ll ans = (1 + (max_d >= 1? tmp[1] : 0)) % MOD;

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