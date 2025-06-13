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
    int n, m; cin >> n >> m;
    vector<string> v(n);

    for (int i = 0; i < n; ++ i) {
        cin >> v[i];
    }

    vector<vector<bool>> rl(n, vector<bool>(m, 0));
    for (int i = 0; i < n; ++ i) {
        rl[i][0] = 1;
        for (int j = 1; j < m; ++ j) {
            rl[i][j] = rl[i][j-1] && (v[i][j-1]=='1');
        }
    }

    vector<vector<bool>> rt(n, vector<bool>(m, 0));
    for (int j = 0; j < m; ++ j) {
        rt[0][j] = 1;
        for (int i = 1; i < n; ++ i) {
            rt[i][j] = rt[i-1][j] && (v[i-1][j]=='1');
        }
    }

    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            if (v[i][j] == '1') {
                if (rl[i][j] || rt[i][j]) continue;
                else {
                    cout << "NO" << endl;
                    return;
                }
            }    
        }
    }

    cout << "YES" << endl;
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