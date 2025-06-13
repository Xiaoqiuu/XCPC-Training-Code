#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <iomanip>
#include <set>
#include <queue>
#include <cctype>
#include <climits>
#include <cstdint>

using namespace std;
using ll = long long int;
using ld = long double;

#define akitama return 0
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define fi first
#define se second
#define lowbit(x) (x&-(x))

constexpr int N = 1e5 + 7;
vector<int> dp(n, -1);
int fib(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    int ans = fib(n-1) + fib(n-2);
    dp[i] = ans;
    return ans;
    // else return dfs(n-1) + dfs(n-2);
}

void solve() {
    // vi a(N, 0);
    int n; cin >> n;
    cout << dfs(n) << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _;
    cin >> _;
    while (_) {
        solve();
        _--;
    }
    akitama;
}