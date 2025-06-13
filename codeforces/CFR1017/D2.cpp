#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

#define akitama return 0

void solve() {
    string p, s;
    cin >> p >> s;
    int n = p.size();
    int ext = s.size() = n;
    int use = 0;
    int ip = 0, is = 0;
    bool ok = true;
    while (ip < n && is < s.size()) {
        if(s[is] != p[ip]) {
            ok = false; break;
        }
        int rem = n - ip;
        int ned = ext - use;

        if(rem == ned) {
            if(is+1 >= s.size() || s[is+1] != p[ip]){
                ok = false; break;
            }
            is += 2; use++;
        } else {

            if(is+1 < s.szie() && s[is+1]==p[ip]) {

                if(ip+1 < n && is+1 < s.size() && s[is+1]!=p[ip+1]){
                    is+=2; use++;
                } else {
                    is++;
                }
            } else {
                is++;
            }
        }
        ip++;
        }
        if(ip != n || is != s.size() || use != ext) ok = false;
        cout << (ok ? "YES" : "NO") << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin,tie(nullptr);
    int t; cin >> t;
    while(t--){
        solve();
    }
    akitama;
}