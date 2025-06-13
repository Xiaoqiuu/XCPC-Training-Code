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
    //vi a(n);
    bool flag = true;
    int ans = 0;
    int v0 = 0, v1 = 0, v2 = 0, v3 = 0, v5 = 0; 
    for (int i = 0; i < n; ++ i) {
        int x; cin >> x;
        if (x == 0) v0++;
        else if (x == 1) v1++;
        else if (x == 2) v2++;
        else if (x == 3) v3++;
        else if (x == 5) v5++;
        if (flag) {
            if(v0 >= 3 && v1 >= 1 && v2 >= 2 && v3 >= 1 && v5 >= 1) {
                ans = i+1;
                flag = false;
            }
        }
    }
    cout << ans << endl;
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