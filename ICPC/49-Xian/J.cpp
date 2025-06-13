#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cfloat>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <numeric>
#include <iomanip>

using namespace std;

#define akitama return 0
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define pb push_back
#define fi first
#define se second
#define lowbit(x) (x&-(x))
/*
    Akitama's Template
    Created Time : 2025/04/16 13:35
    Target Platform : up to C++23
*/

// const int N = 1e5 + 7;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a==b)
        cout << a*(a-1)/2+a << endl;
    else if (a%2==1 && b%2==1) 
        cout << (a+b)/2 << endl;
    else if (a%2==0 && b%2==0)
        cout << min(a, b) * max(a, b)/2 << endl;
    else
        cout << a*b/2 << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;// cin >> _;
    while (_) {
        solve();
        _--;
    }
    akitama;
}
