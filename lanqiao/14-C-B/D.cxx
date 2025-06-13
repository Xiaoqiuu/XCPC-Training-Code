#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long
#define vl vector<long long>
#define vi vector<int>
#define pip pair<int,pair<int, int>>
#define si set<int>

void solve() {
  int n;cin >> n;
  ll max_time = -1;
  vi t(n), d(n), l(n), ans(n);
  si ans_2;
  for(int i = 0;i < n;++ i){
    cin >> t[i] >> d[i] >> l[i];
    max_time = max(max_time, t[i] + d[i] +l[i]);
  }

  // for(int i = 0;i < n;++ i) {
  //   ans.push_back();
  // }

  for(int cur_t = 0;i <= max_time;++ cur_t) {
    vi idx;int enm_idx = INT_MAX;
    for(int i = 0;i < n;i ++){
      if(cur == v[i]){
        idx.push_back(i);
      }
    }
    for(int i = 0;i < idx.size();++ i){
      
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int _;cin >> _;
  while(_ --){
    solve();
  }
  return 0;
}