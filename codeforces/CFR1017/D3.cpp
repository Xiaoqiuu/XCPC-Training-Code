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
    string p, s; cin >> p >> s;
    int ip = 0, is = 0;
    bool f = 1;
    for (;ip<p.size(), is < s.size(); ++ ip) {
        if(p[ip]=='L'){
            if(s[is] == 'R') { f = 0; break; }
            is++;
            if(s[is] == 'R' && is < s.size())  { f = 0; break; }
            is++;
        } else {
            if(s[is] == 'L') { f = 0; break; }
            ip++;
            if(s[is] == 'L' && is < s.size())  { f = 0; break; }
            ip++;
        }
    }
    cout << (f? "YES" : "NO") << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    
    int _; cin >> _;
    // int _ = 1;
    
    while (_) { solve(); _--; }

    akitama;
}