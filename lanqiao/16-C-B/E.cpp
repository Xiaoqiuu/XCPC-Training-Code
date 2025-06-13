#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define akitama return 0
#define vi vector<int>

void solve() {
    int n, m; cin >> n >> m;
    vi a(n);
    ll ans = 0;
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    //1 2 4 5
    // 
    vector<ull> b(n-1);
    for (int i = 0; i < n - 1; ++ i) {
        b[i] = (a[i] +a[i+1])*(a[i+1] - a[i]);
    }

    for (int i = 0; i < m - 1; ++ i) {
        ans += b[i];
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    solve();
    akitama;
}