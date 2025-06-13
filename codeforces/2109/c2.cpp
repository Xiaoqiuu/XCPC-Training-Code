#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <utility>
#include <numeric>
#include <iomanip>
using namespace std;
using ll = long long int;
using ld = long double;
#define akitama return 0
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>

ll llmin(ll a, ll b)
{
    if (a < b) return a;
    else return b;
}

void solve() {
    int n; cin >> n;
    string s;
    cout << "mul 9" << endl;
    cout.flush();
    cin >> s;
    if (s == "-1") return;
    cout << "digit" << endl;
    cout.flush();
    cin >> s;
    if (s == "-1") return;

    cout << "digit" << endl;
    cout.flush();
    cin >> s;
    if (s == "-1") return;

    cout << "add " << ( n - 9 ) << endl;
    cout.flush();
    cin >> s;
    if (s == "-1") return;

    cout << "!" << endl;
    cout.flush();
    cin >> s;
    if (s == "-1") return;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}