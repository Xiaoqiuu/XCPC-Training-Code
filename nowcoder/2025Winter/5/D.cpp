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
#define endl '\n'
//Akitama 2.8
#define lowbit(x) ((x) & (-x))

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

void solve() {
    ll n;cin >> n;
    string s;cin >> s;
    ll ans = 0;
    for (int i = 0;i < n; ++ i) {
        if (s[i] == '0') s[i] = '1'; else s[i] = '0';
    }
    vi pre(n+1, 0);
    for (int i = 0;i < n; ++ i) {
        pre[i + 1] = pre[i] + (s[i] - '0');
    }
    for(int i = 1;i <= n; ++ i) {
        ll res = 1;
        for (int l = 1,r = l + i - 1; ;l += i, r += i) {
            if (l > n) break;
            if (r > n) {
                r = n;
                if (pre[r] != pre[l - 1] && pre[r] != pre[l - 1] + (r - l + 1))
                    res++;
                break;
            } else {
                if (pre[r] != pre[l - 1] && pre[r] != pre[l - 1] + (r - l + 1))
                    res++;
            }
        }
        ans ^= res;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    //int _;cin >> _;
    int _ = 1;
    while (_--) { solve(); }
    akitama;
}