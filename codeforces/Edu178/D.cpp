#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define akitama return 0
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
using ll = long long int;
vll a;
vi prime, minp;
const int N = 1e5 + 7;

// 线性筛法
void sieve(int n = 1e7) {
    minp.assign(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        if (!minp[i]) {
            minp[i] = i;
            prime.pb(i);
        }
        for (auto j : prime) {
            if (j > minp[i] || j > n / i) break;
            minp[i * j] = j;
        }
    }
}

bool isprime(int n) {
    return minp[n] == n;
}

int minprm(int x) {
    return minp[x];
}

int Kth(int k) {
    return prime[k-1];
}

void solve() {
    int n; cin >> n;
    a.resize(n + 1); 
    for (int i = 1; i <= n; ++i) cin >> a[i];
    

    ll sum = 0;
    for (int i = 1; i <= n; ++i) sum += Kth(i);
    
    sort(a.begin() + 1, a.end());  
    ll cnt = accumulate(a.begin() + 1, a.end(), 0LL);
    
    if (cnt >= sum) {
        cout << 0 << '\n';
        return;
    }
    
    for (int i = 1; i <= n; ++i) {
        cnt -= a[i];
        sum -= Kth(n - i + 1); 
        if (cnt >= sum) {
            cout << i << '\n';
            return;
        }
    }
    cout << n << endl;
    return;
}

signed main() {
    sieve();  
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}