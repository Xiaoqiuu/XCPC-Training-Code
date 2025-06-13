#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define akitama return 0
 
void solve(){
    int n;cin >> n;
    vll a(n);
    for(auto &x: a) cin >> x;
    bool ok = true;
    for(int p=1; p<=n; ++p){
        ll required = 2LL * max((int)(p-1), (int)(n-p));
        if(a[p-1] <= required){
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES\n"; else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while(t --){
        solve();
    }
    akitama;
}