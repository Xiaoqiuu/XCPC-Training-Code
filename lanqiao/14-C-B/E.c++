#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define akitama return 0
#define ll long long
#define vi vector<int>
#define vl vector<ll>

int modCalc(int num){
    int res = 0;
    ll temp = num, mod = 10;
    while(temp % mod != num) {
        mod *= 10;
        res++;
    }
    return res + 1;
}
int firstDigit(ll x){
    while(x >= 10) x /= 10;
    return (int)x;
}
int lastDigit(ll x){
    return (int)(x % 10);
}
void solve(){
    int n; cin >> n;
    vl a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vi dp(10, 0);
    int mx = 0;
    for(int i = 0; i < n; i++){
        int f = firstDigit(a[i]), l = lastDigit(a[i]);
        int candidate = dp[f] ? dp[f] + 1 : 1;
        dp[l] = max(dp[l], candidate);
        mx = max(mx, dp[l]);
    }
    cout << n - mx;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    akitama;
}
