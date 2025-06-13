#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <climits>
#include <cstdlib>
#include <bitset>
#include <queue>
#include <set>
#include <cctype>
#include <iomanip>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define akitama return 0
#define ull unsigned long long int
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x&(-x))

const int BITS = 30;

void solve() {
    int n; cin >> n;
    vector<ull> a(n);
    for (auto& i : a) cin >> i;
    vi cnt(BITS, 0);
    for (int i = 0; i < n; ++ i) {
        for (int b = 0; b < BITS; ++ b) {
            if(a[i] & (1u << b)) {
                cnt[b]++;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++ i) {
        ll sum = 0;
        for (int b = 0; b < BITS; ++ b){
            if(a[i] & (1u << b)) {
                sum += (ll)(n - cnt[b]) * (1LL << b);
            } else {
                sum += (ll)cnt[b] * (1LL << b);
            }
        }
        ans = max(ans, sum);
    }

    
    cout << ans << endl;

}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    
    int _; cin >> _;
    // int _ = 1;
    
    while (_) { solve(); _--; }

    akitama;
}