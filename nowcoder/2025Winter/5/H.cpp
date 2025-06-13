#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <utility>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back
#define sl set<ll>
#define akitama return 0
//Akitama 2.8
#define lowbit(x) ((x) & (-(x)))

const int MOD = 1000000007;
const int MAXN = 100005;

void solve() {
    int n, k;
    cin >> n >> k;
    vi arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    const int m = 998244353;
    vector<vi> F(n + 1, vi(n + 1, 0));
    vector<vi> H(n + 1, vi(n + 1, 0));
    
    for (int l = 1; l <= n; l++) {
        int mn = INT_MAX, mx = 0;
        for (int r = l; r <= n; r++) {
            mn = min(mn, arr[r]);
            mx = max(mx, arr[r]);
            ll prod = (ll)mx * mn % m;
            F[l][r] = (int)prod;
            H[l][r] = (H[l][r - 1] + F[l][r]) % m;
        }
    }
    
    vector<vi> dp(k + 1, vi(n + 1, 0));
    for (int j = 1; j <= n; j++) {
        dp[1][j] = H[1][j];
    }
    
    for (int t = 2; t <= k; t++) {
        vi pre(n + 1, 0);
        for (int i = t - 1; i <= n; i++) {
            pre[i] = (pre[i - 1] + dp[t - 1][i]) % m;
        }
        for (int j = t; j <= n; j++) {
            int L = t - 1;
            int sumdp = (pre[j - 1] - (L == 1 ? 0 : pre[L - 1]) + m) % m;
            int sumF = (H[L + 1][j] - H[L + 1][L] + m) % m;
            dp[t][j] = (sumdp + sumF) % m;
        }
    }
    
    cout << dp[k][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--) {
        solve();
    }
    akitama;
}
