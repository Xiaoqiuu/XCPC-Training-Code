#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N];

int main() {
    unordered_map<ll, ll> mp;
    ll n; cin >> n;
    
    if (n == 1) {
        cout << -1 << endl;
        return 0;
    }
    
    for (ll i = 0; i < n; ++i) 
        cin >> a[i];
    
    for (ll i = 0; i < n; ++i)
        mp[a[i]] = i;

    ll ans = 0;
    bool vi[N] = {false}; 
    
    for (ll i = 0; i < n; ++i) {
        if (vi[i] || a[i] == a[(i + 1) % n]) continue;
        
        ll count = 0;
        ll j = i;
        
        while (!vi[j]) {
            vi[j] = true;
            j = mp[a[(j + 1) % n]];
            count++;
        }

        if (count > 1) 
            ans += (count - 1); 
    }
    
    cout << ans << endl; 
    return 0;
}
