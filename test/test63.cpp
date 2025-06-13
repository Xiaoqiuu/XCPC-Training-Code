// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int, int>
#define vl vector<ll>
#define akitama return 0

void solve() {
  int n; cin >> n;
  vector<pii> a(n+1);
  ll sum = 0;
  for (auto& [w, p] : a) {
    cin >> w >> p;
    sum += w;
  } sort(a.begin(), a.end());
  // w p
  vl w(n+1, 0);
  
  // for (int i = 1; i <= n; ++ i) {
  //   ll W, P; cin >> W >> P;
  //   w[P] = W;
  //   sum += w[P];
  // }
  ll ans = 0;
  ll sw = 0, pos = 0;
  for (auto& [ w , p ] : a) {
    if (sw * 2 < sum && sum <= 2 * (w + sw)) {
      pos = p;
      break;
    }
    sw += w;
  }
  for (auto& [ w, p ] : a) {
    ans += w * abs(p - pos);
  }

  cout << ans << endl;
}

int main()
{
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int _ = 1; // cin >> _;
  while (_) {
    solve();
    _--;
  }
  akitama;
}