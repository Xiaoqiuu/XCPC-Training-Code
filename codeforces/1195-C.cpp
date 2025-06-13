#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;
#define akitama return 0
#define vll vector<ll>
signed main() {
    int n; cin >> n;
    vll a(n+1, 0), b(n+1, 0);
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++ i) {
        cin >> b[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(3, 0));
    dp[1][1] = a[1];
    dp[1][2] = b[1];
    ll cnta =a[1], cntb = b[1];
    for (int i = 2; i <= n; ++ i) {
        dp[i][1] = cntb + a[i];
        dp[i][2] = cnta + b[i];
        cnta = max(cnta, dp[i][1]);
        cntb = max(cntb, dp[i][2]);
    } 

    cout << max(dp[n][1], dp[n][2]) << endl;
    akitama;
}