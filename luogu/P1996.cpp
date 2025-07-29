#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
signed main() {
    int n, m; cin >> n >> m;
    queue<int> qu;
    ll cnt = 1;
    for (int i = 1; i <= n; ++ i) {
        // if (++cnt > n) s = 1;
        qu.push(i);
    }
    while (!qu.empty()) {
        if (cnt == m) {
            cout << qu.front() << " ";
            qu.pop();
            cnt = 1;
        } else if (cnt != m) {
            cnt+=1;
            qu.push(qu.front());
            qu.pop();
        }
    }
    #define akitama return 0
    akitama;
}