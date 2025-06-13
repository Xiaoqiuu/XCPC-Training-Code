#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;cin >> n >> m;
    int ans = 0, tmp = 0;
    for(int i=1; i<=n; i++) {
       char ch[10000];
       cin >> ch;
       m -= strlen(ch);
       if(m < 0) ans = tmp;
       else tmp ++;
    }
    ans = tmp;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--) {
        solve();
        }
    return 0;
}