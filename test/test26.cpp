#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long
#define akitama return 0
#define fast_io cin.tie(nullptr)->ios::sync_with_stdio(false)
#define endl '\n'

ll mygcd(ll a, ll b){
    if(b == 0) return a;
    else return mygcd(b, a % b);
}
void solve() {
    int a, b;
    cin >> a >> b;
    cout << mygcd(a, b) << endl;
}

signed main(){
    fast_io;
    int _ = 1;
    while (_--){
        solve();
    }
    akitama;
}