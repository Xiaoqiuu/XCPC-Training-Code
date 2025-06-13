#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

#define ll long long
#define ul unsigned long long
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define akitama return 0
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MOD = 998244353;
const int N = 100005;

// 判断 x 是否为完全平方数
bool pre(ll x) {
    ll r = (ll) sqrt(x);
    return r * r == x;
}

void solve() {
    int n;
    cin >> n;
    
    ll total = (ll)n * (n + 1) / 2;
    if(pre(total)) {
        cout << -1 << "\n";
        return;
    }
    
    
    vi perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
    }
    
    ll prefix = 0;
    
    for (int i = 0; i < n; i++) {
        
        if(pre(prefix + perm[i])) {
            
            swap(perm[i], perm[i+1]);
            
            prefix += perm[i];
        } else {
            prefix += perm[i];
        }
    }
    
    
    for (int i = 0; i < n; i++) {
        cout << perm[i] << " ";
    }
    cout << "\n";
}

signed main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}
