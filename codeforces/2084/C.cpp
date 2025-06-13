#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

#define ll long long
#define ul unsigned long long
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define akitama return 0
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MOD = 998244353;
const int N = 100005;

void solve() {
    int n; cin >> n;
    vi a(n), b(n), p(n), ia(n);

    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        a[i] --;
        ia[a[i]] = i;
    }

    for (int i = 0; i < n; ++ i) {
        cin >> b[i];
        b[i] --;
        p[a[i]] = b[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; ++ i) {
        if (p[i] == i || p[p[i]] != i) {
            cnt ++;
        }
    }
    if (cnt > 1) { cout << -1 << endl; return; }
    vi v(n);
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++ i) {
        if (p[i] == i)
        {
            v[ia[i]] = n / 2;
        } else if (p[i] > i) {
            v[ia[i]] = l ++;
            v[ia[v[i]]] = r--;
        }
    }

    vector<array<int, 2>> op;
    for (int i = 0; i < n; ++ i) {
        while (v[i] != i) {
            op.pb({i, v[i]});
            swap(v[i], v[v[i]]);
        }
    }

    cout << op.size() << endl;
    for (auto [n1, n2] : op) {
        cout << n1 + 1 << " " << n2 + 1 << endl;
    }
    // for (int i = 0; i < n; ++ i) {
    //     if (a[i] == b[i] && a[i] % 2 == 0) {
    //         cout << -1 << endl;
    //         return;
    //     } else if (a[i] == b[i]) tmp = i;
    // }
    // vcetor<pii> ans;
    // if (n & 1) {
    //     int target = (n + 1) / 2;
    //     if (tmp != target) {
    //         swap(a[tmp], a[target]);
    //     }
    // }
    // 00000010
    // 00000001
    // 00000100
    // 00001000
    // 00001010
}

signed main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _;cin >> _;
    //int _ = 1;
    while (_) {
        solve();
        _--;
    }
    akitama;
}