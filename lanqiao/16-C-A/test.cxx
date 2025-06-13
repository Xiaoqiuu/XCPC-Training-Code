#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long int
#define akitama return 0
#define lowbit(x) ((x) & -(x))

void solve() {
    ll l, r; cin >> l >> r;
    ll t = 1, cnt = 0;
    while (l > 1) {
        t *= 2;
        l --;
    }
    t += r - 1;
    while ( t ) { 
        t-=lowbit(t);
        if(t) cnt++;
    }

    if(cnt%2!=0) cout << "BLACK"<<endl;
    else cout << "YES\n";
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_) {
        solve();
        _--;
    }
    akitama;
}