#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define akitama return 0
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second

const int MOD = 1e9;

int main(){
    int n, k; cin >> n >> k;
    if(n<k) { cout << 1 << endl; akitama; }
    vi a(n+1, 0);
    vi pre(n+2, 0);

    for (int i = 0; i < k; ++ i){
        a[i]=1;
        pre[i+1] = (pre[i]+a[i]) % MOD;
    }

    for (int i = k; i<= n; ++ i) {
        a[i] = (pre[i] - pre[i-k]) % MOD;
        if (a[i] < 0) a[i] += MOD;
        pre[i+1] = (pre[i]+a[i]) %MOD;
    }

    cout << a[n] << endl;

    akitama;
}
