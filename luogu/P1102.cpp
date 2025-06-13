#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
#define akitama return 0
#define ll long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<ll, ll> mp;
    ll n, c, ans = 0;
    cin >> n >> c;
    vector<ll> a(n);
    for(auto &i : a){
        cin >> i, mp[i]++;
    }
    for(ll i = 0;i < n;++ i){
        ll tmp = a[i] - c;
        if(mp.count(tmp))ans += mp[tmp];
    }
    cout << ans << '\n';
    akitama;
}