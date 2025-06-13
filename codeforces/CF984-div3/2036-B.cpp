#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
using namespace std;
#define akitama return 0
using ll = long long;

const int N = 2e5 + 5;

void solve() {
    int a[N] = {0};
    int n = 0, k = 0, b = 0, c = 0;
    ll ans = 0;
    cin >> n >> k;
    set<int> s;
    for(int i = 1; i <= k;i ++) {
        cin >> b >> c;
        s.insert(b);
        a[b] += c;
    }
    int hq = 0, tmp[s.size()];
    for(auto i : s) {
        tmp[hq] = a[i];
        hq ++;
    }

    sort(tmp, tmp + s.size(), [](const int &u, const int &v)
    {
        return u > v;
    });
    for (int i = 0; i < s.size(); i++) {
        if (i >= n) break;
        ans += tmp[i];
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while(t --) {
        solve();
    }
    akitama;
}