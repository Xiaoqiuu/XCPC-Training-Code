//n个物品 m个收纳箱 每个容量k，每件物品体积a[i]
#include <iostream>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
//ll a[101][10010];

ll box_item_check(ll T) {
    ll ans = 0;
    
    while (T--) {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> volumes(n);
        
        for (int j = 0; j < n; j++) {
            cin >> volumes[j];
        }
        
        int c = 0;
        ll cur = k;
        for (int j = 0; j < n; j++) {
            while (c < m && volumes[j] > cur)
                c++, cur = k;
            if (c == m)  break;
            cur -= volumes[j];
            ans++;
        }
    } 

    return ans;
}

int main() {
    ll T;
    cin >> T; 
    cout << box_item_check(T) << endl; 
    return 0;
}