#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
    vl a(n);
    ll cnt = 0;
    for (int i = 0; i< n; ++ i) {
        cin >> a[i];
        if(a[i] == 0) cnt ++;
    }
    if(cnt == 0) {
        cout << "1\n1 " << n << endl;
        return;
    } else if (cnt == n) {
        cout << "3\n" << n - 1 << " " << n << endl;
        cout << 1 << " " << n - 2 << endl;
        cout << "1 2" << endl;
        return;
    }

    vi ans;
    vector<pii> op;

    for (int i = 0; i < n; i ++) {
        if (a[i] == 0) {
            if (i!=n - 1) {
                op.pb({ans.size()+1, ans.size()+2});
                ans.push_back(5);
                i ++;
            } else {
                op.push_back({ans.size(), ans.size()+1});
                ans.pop_back();
                ans.push_back(5);
            }
        } else {
            ans.push_back(5);
        }
    }

    op.pb({1, ans.size()});
    cout << op.size() << endl;
    for (auto p : op) {
        cout << p.fi << " " << p.se << endl;
    }

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