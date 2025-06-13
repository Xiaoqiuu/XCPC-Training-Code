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

void solve() {
    int n, x;
    cin >> n >> x;
    if (n == 1) {
        cout << x << "\n";
        return;
    }
    int MSK = (1 << 30) - 1;
    int k = n + 1;
    for (int i = 1; i <= n + 1; i++) {
        if (i & ((~x) & MSK)) {
            k = i;
            break;
        }
    }
    int lim = min(n, k), rmx = 1;
    auto F = [&](int r) -> int {
        int p = 0;
        while ((1 << p) < r) p++;
        return (1 << p) - 1;
    };
    for (int r = 1; r <= lim; r++) {
        int fr = F(r);
        if (fr == x)
            rmx = r;
        else if (r + 1 <= n)
            rmx = r;
    }
    vector<int> D;
    for (int i = 0; i < rmx; i++) D.pb(i);
    int frmx = F(rmx);
    if (frmx != x) {
        int v = x & ((~frmx) & MSK);
        D.pb(v);
    }
    vector<int> an;
    for (auto v : D) an.pb(v);
    while (an.size() < (size_t)n) an.pb(0);
    for (int i = 0; i < n; i++) cout << an[i] << (i == n - 1 ? "\n" : " ");
}

signed main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _;cin >> _;
    //int _ = 1;
    while (_) {
        solve();
        _--;
    }
    akitama;
}