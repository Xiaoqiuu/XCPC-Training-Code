#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define ll long long
#define akitama return 0
#define vi vector<int>

const int MOD = 1e9 + 7;
int max_len = INT_MIN, min_len = INT_MAX;

void solve() {
    int n; cin >> n;
    vi a(n);
    vi cnt(n);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        max_len = max(max_len, a[i]);
        min_len = min(min_len, a[i]); 
        cnt[a[i]]++;
    }
    ll ans = 0;
    
    for (int i = min_len + 1; i <= max_len; ++ i) {
        if (cnt[i] <= 1) continue;
        for (int j = min_len; j <= i / 2; ++ j) {
            if (cnt[j] && cnt[i - j]) {
                if (j != i - j) {
                    ans += ((cnt[i] * (cnt[i] - 1) >> 1) * cnt[j] * cnt[i - j]) % MOD;
                } else if (cnt[j] >= 2) {
                    ans += ((cnt[i] * (cnt[i] - 1) >> 1) * (cnt[j] * (cnt[j] - 1) >> 1) % MOD)%MOD;
                }
            }
        }
    }
    
    printf("%lld\n", ans % MOD);
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    solve();
    akitama;
}