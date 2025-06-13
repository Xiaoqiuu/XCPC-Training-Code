#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
ll a[N];

ll check (ll a[],ll ans,int k,int n) {
    int cnt = 0;
    for (int i = 1; i <= n - k + 1; ++ i) {
        cnt = 0;
        for(int j = i, k = i + k - 1; cnt <= 1 && j <= k; ++ j, -- k) {
            cnt += a[j] != a[k];
        }
        if (cnt == 1) {
            ans ++;
        }
    }
    return ans;
    }
    /*
    ll check(ll a[], ll ans, int k, int n) {
    for (int i = 1; i <= n - k + 1; ++i) {
        int left = i, right = i + k - 1;
        int mismatchCount = 0;
        
        while (left < right) {
            if (a[left] != a[right]) {
                mismatchCount++;
            }
            left++;
            right--;
        }
        if (mismatchCount == 1) {
            ans++;
        }
    }
    return ans;
}
*/
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll ans = 0;
    int k, n;cin >> n >> k;
    for (int i = 1;i <= n; ++ i) {
        cin >> a[i];
    }
    ans = check(a,k,n,ans);
    cout << ans << endl;

    return 0;
}

//huiwen

