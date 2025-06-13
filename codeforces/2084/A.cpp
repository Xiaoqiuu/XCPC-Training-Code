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
    if (n % 2 == 0) cout << -1 << endl;
    else {
        cout << n << " ";
        for (int i = 1; i < n; ++ i) {
            cout << i << " ";
        }cout << endl;
    }

    int a[10] = {1, 7, 6, 5, 2, 3, 4, 8, 9, 10};
    int b = a.size();
    cout << b << endl;
    // 1 7 6 5 2 3 4
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