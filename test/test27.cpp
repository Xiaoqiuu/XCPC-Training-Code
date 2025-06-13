#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define akitama return 0

void solve();

signed main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    while (_) {
        solve();
        _--;
    }
    akitama;
}

void solve() {
    for(int i = 0; i < n; ++ i) {
        if (i == 0) s[i] = a[i];
        else s[i] = s[i-1] + a[i];
    }
    partial_sum(s.begin(), s.end(), s.begin());
}