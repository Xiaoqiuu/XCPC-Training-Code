#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <utility>
//#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back
#define sl set<ll>
#define akitama return 0
//Akitama 2.8
#define lowbit(x) ((x) & (-x))

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

void solve() {
    ll t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    ll n, x, y, res1 = 0, res2 = 0;
    cin >> n >> x >> y;
    string a, b, c;
    cin >> a >> b >> c;
    for (int i = 0;i < n; ++ i) {
        if(a[i]=='0' && b[i]=='1'&&c[i]=='0') t1++;
        if(a[i]=='1' && b[i]=='0'&&c[i]=='0') t2++;
        if(a[i]=='0' && b[i]=='0'&&c[i]=='1') t3++;
        if(a[i]=='1' && b[i]=='1'&&c[i]=='1') t4++;
    }
    res1 = x * (t1 + t2 + t3 + t4);
    ll sum = t1 + t2 + t3 + t4;
    if(max({t1,t2,t3,t4}) <= sum / 2) res2 = sum / 2 * y + ((sum % 2 == 1)?x : 0);
    else res2 = (sum - max({t1,t2,t3,t4})) * y + x * (max({t1,t2,t3,t4})) - (sum - max({t1,t2,t3,t4}));
    cout << min(res1, res2) << endl;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    //int _;cin >> _;
    int _ = 1;
    while (_--) { solve(); }
    akitama;
}