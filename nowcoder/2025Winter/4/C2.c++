#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <cctype>

using namespace std;

#define akitama return 0
#define ll long long
#define vl vector<long long>
#define vvl vector<vl>

const int MOD = 1e9 + 7;
 
ll calp(int x){
    ll res = 1;
    while(x--) res = (res * 2) % MOD;
    return res;
}
 
// void solve(){

// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){

        int n;
        string s;
        cin >> n >> s;

        if(n == 1){
            int p = 0;
            for(char c : s) if(c == '?') p ++;
            cout << calp(p) % MOD << "\n";continue;
        }
        int _cnt = 0;
        for(char c : s) if(c == '?') _cnt ++;
        int ep0 = (s[0]=='?');
        int epn = (s[n-1]=='?');
        int p0 = _cnt - ep0 - epn;
        ll ce, cd;
        if(s[0] != '?' && s[n-1] != '?'){
            if(s[0] == s[n-1]) { 
                ce = 1; cd = 0; 
                }
            else { ce = 0; cd = 1; }
        } else if(s[0]=='?' && s[n-1] != '?'){
            ce = 1; cd = 1;
        } else if(s[0]!='?' && s[n-1]=='?'){
            ce = 1; cd = 1;
        } else {
            ce = 2; cd = 2;
        }
        ll tmp = calp(p0);
        ll ans = ( tmp * ( ((ll)(n-2) * ce) % MOD + (2 * cd) % MOD ) ) % MOD;
        cout << ans % MOD << "\n";
    }
    akitama;
}
