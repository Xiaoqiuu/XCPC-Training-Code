#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back
#define sl set<ll>
#define akitama return 0

inline ll mySqrt(ll x) {
    if (x == 0) return 0;
    return (ll)sqrt(x);
}

inline bool isP2(ll x) {
    return x > 0 && (x & (x - 1)) == 0;
}

bool proc(ll n, ll m) {
    if (n == m) return true;
    if (n == 0) return m == 0;
    if (n == 1) return isP2(m);
    
    
    int dep = 50;
    
    
    deque<pair<ll, int>> que;
    unordered_set<ll> vis;
    
    
    que.push_back({n, 0});
    vis.insert(n);
    
    while (!que.empty()) {
        auto p = que.front(); que.pop_front();
        ll cur = p.first;
        int d = p.second;
        
        if (d > dep) continue;
        
        
        if (cur <= LLONG_MAX / 2) {
            ll nxt = cur * 2;
            if (nxt == m) return true;
            if (!vis.count(nxt)) {
                vis.insert(nxt);
                que.push_back({nxt, d + 1});
            }
        }
        
        
        ll nxt = mySqrt(cur);
        if (nxt == m) return true;
        if (!vis.count(nxt)) {
            vis.insert(nxt);
            que.push_back({nxt, d + 1});
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) {
        ll n, m; cin >> n >> m;
        cout << (proc(n, m) ? "Yes" : "No") << "\n";
    }
    
    akitama;
}
