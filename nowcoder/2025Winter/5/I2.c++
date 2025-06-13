#include <iostream>
#include <cmath>
using namespace std;

#define ll long long

bool chk(ll x, ll n) {
    if (!n) return false;
    
    ll l = x * x, h = (x + 1) * (x + 1) - 1;
    if (l > h) return false;
    
    ll c = n, k = 0;
    while (c < l) {
        if (c > h) return false;
        c *= 2;
        k++;
        if (c > h) return false;
    }
    if (c > h) return false;
    
    ll m = 0;
    while (c <= h / 2) {
        c *= 2;
        m++;
    }
    return k <= k + m;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    
    if (n == m) {
        cout << "Yes\n";
        return;
    }
    
    if (!n || !m) {
        cout << "No\n";
        return;
    }
    
    ll x = m;
    int s = 0;
    
    while (s <= 60) {
        if (x == n) {
            cout << "Yes\n";
            return;
        }
        
        if (x < n) {
            cout << "No\n";
            return;
        }
        
        while (x % 2 == 0) {
            x /= 2;
            if (x == n) {
                cout << "Yes\n";
                return;
            }
        }
        
        if (chk(x, n)) {
            cout << "Yes\n";
            return;
        }
        
        x = (x + 1) * (x + 1) - 1;
        s++;
    }
    
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;cin >> _;
    while(_--)
    solve();
    return 0;
}
