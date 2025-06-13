#include <iostream>
#include <climits>
using namespace std;

using ll = long long;

void solve() {
  int x, y;
  int num, query;
  cin >> num >> query;
  int exp[num + 1] = {0};
  while(query --) {
    int op;cin >> op;
    switch(op) {
      case 1:cin >> x >> y;for(int i = 1;i <= x; ++ i) {exp[i]+= y;}break;
      case 2:cin >> x >> y;for(int i = x;i <= num; ++ i) {exp[i]-= y;}break;
    }
  }
  int ans = INT_MIN;
  for (int i = 1;i <= num; ++ i) {
    if(exp[i] > ans) ans = exp[i];
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}