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
    string p, s;cin >> p >> s;
    int x = p.size() - s.size();
    int ip = 0, is = 0;
    bool f = 1;
    while (ip < p.size() && is < s.size()) {
        if (s[is] != p[ip]) {
            f = 0;
            break;
        }
        int remain = p.size() - ip;
        int rc = s.size() -is;
        bool ff = 0;

        if (remain ==1 && x > 0) ff = 1;
        else if (remain > 1) {
            if (x > (remain - 1)) ff = 1;
            else if (ip + 1 < p.size() && is + 1 < s.size() && s[is+1]!=p[ip+1])
            ff = 0;
        }

        if (ff) {
            if (is + 1 >= s.size() || s[is+1]!=p[ip]) {
                f = 0;
                break;
            }
            is += 2;
            x--;
        } else {
            is +=1;
        }
        ip++;
    }
    if (ip!=p.size()||is!=s.size() || x!= 0) f = 0;
    cout << (f? "YES" : "NO") << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    
    int _; cin >> _;
    // int _ = 1;
    
    while (_) { solve(); _--; }

    akitama;
}