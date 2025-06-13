#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll unsigned long long int
#define ld long double
#define akitama return 0

void solve() {
  // TLE 
  int n;
  ld d;
  cin >> n >> d;
  ll mul = 1 << n;
  d *= mul;
  cout << (d - (ll)d > 0.5? (ll)d + 1 : (ll)d) << endl;
}

int main()
{
  //cin.tie(nullptr)->ios::sync_with_stdio(false);  
  int _ = 1;
  while (_--) solve();
  akitama;
}