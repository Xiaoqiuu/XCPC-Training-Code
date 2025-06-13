#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <utility>
#include <climits>

using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
//#define ll long long
//#define ul unsigned long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define akitama return 0
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) (x&-(x))

const int MOD = 998244353;
const int N = 100005;

void solve() {
    int n; cin >> n;
    cout << (n * n / 4) + 1 << endl;
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