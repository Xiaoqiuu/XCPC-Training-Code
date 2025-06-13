#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
#define akitama return 0
#define ll long long int
#define vl vector<ll>
signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int n; cin >> n;
    vl a(n);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }

    map<ll, ll> mp;
    for (ll i : a)
        mp[i]++;

    vl ans;
    for (ll i : a) {
        if (mp[i] == 1) {
            ans.push_back(i);
        }
    }

    if (ans.empty()) { cout << "-1" << endl; akitama; }
    ll maxv = *max_element(ans.begin(), ans.end());
    for (int i = 0; i< n; ++ i) {
        if (a[i] == maxv) {
            cout << i+1 << endl;
            akitama;
        }
    }

    akitama;
}
// 1 1 1 2 3 4 4 