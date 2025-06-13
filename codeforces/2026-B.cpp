#include <bits/stdc++.h>
using namespace std;
#define akitama return 0;
using ll = long long;
using pir = pair<ll, ll>;
const int N = 2e3 + 5;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[N];
        vector<pir> v;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i > 1)
                v.push_back(pir(a[i] - a[i-1], i - 1)); 
        }
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        sort(v.begin(), v.end());
        int cnt = n, it = 0;
        ll ans = 0;
        bool cell[N] = {false};
        while (cnt) {
            if (cnt == 1)
                break;
            auto [d, i] = v[it++];
            ans = max(ans, d);
            if (!cell[i])
                cnt--;
            if (!cell[i+1])
                cnt--;
            cell[i] = cell[i+1] = true;
        }
        cout << ans << endl;
    }
    akitama;
}