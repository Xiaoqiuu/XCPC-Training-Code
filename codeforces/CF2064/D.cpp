#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define akitama return 0
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define fast_io cin.tie(nullptr)->ios::sync_with_stdio(false)
#define endl '\n'

int a[200000], pxor[200001], m[200001][30];

void solve() {
    int c, i, n, q, p, j, p1, p2;
    int pc, ans = 0;
    cin >> n >> q;
    for(j = 0;j < 30; ++ j) m[0][j] = -1;

    for(i = 0;i < n; ++ i) {
        cin >> a[i];
        for(j = 0;j < 30; ++ j) {
            if(a[i] >> j & 1) m[i + 1][j] = i;
            else m[i + 1][j] = m[i][j];
        }
    }
    pxor[0] = 0;
    for(i = 0;i < n; ++ i) {
        pxor[i + 1] = pxor[i] ^ a[i];
    }
    for(;q > 0; -- q) {
        cin >> c;
        ans = 0;
        pc = n;
        while(true) {
            if(c == 0) break;
            for (j = 29;j > -1; j --) {
                if(c >> j & 1) break;
            }
            p = j;
            p1 = m[pc][p];
            p2 = -1;
            for(j = 29;j > p;j --){
                p2 = max(p2, m[pc][j]);
            } if(p2 >= p1) {
                ans += pc - 1 - p2;
                break;
            }
            c ^= pxor[pc] ^ pxor[p1 + 1];
            ans += pc - 1 - p1;

            if(p1 == -1 || a[p1] > c) break;
            c ^= a[p1];
            pc = p1;
            ans ++;
        }
        cout << ans << " ";
    } cout << endl;
}

signed main(){
    fast_io;
    int _ ;
    cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}