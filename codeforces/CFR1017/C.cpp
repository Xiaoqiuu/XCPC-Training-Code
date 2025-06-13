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
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x&(-x))

void solve() {
    int n; cin>> n;
    int g[n][n];
    vi cnt(2*n+1, 0);
    for (int i = 0; i < n; ++ i)
        for (int  j = 0; j < n; ++ j) {
        cin >> g[i][j];
        ++ cnt[i+j+1];
    }

    vi res(2*n+1, -1);
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j) {
        int idx = i + j + 1;
        if (res[idx]==-1) {
            res[idx] = g[i][j];
        }
        for (int i = 1; i <= 2 * n; ++ i)
        cout << res[i] << " ";
    cout << endl;
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    
    int _; cin >> _;
    // int _ = 1;
    
    while (_) { solve(); _--; }

    akitama;
}