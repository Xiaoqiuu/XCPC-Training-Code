#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define akitama return 0

const int N = 1e5 + 5;
int n;
int a[N], f[N];

void solve() {
    cin >> n;

    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i) {
        f[i] = 1;
        for (int j = 0; j < i; ++ j) {
            if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }

    cout << ans << endl;

}

signed main() {
    cin.tie()->ios::sync_with_stdio(false);
    int _ = 1;
    while(_) { solve(); _--; }
    akitama;
}