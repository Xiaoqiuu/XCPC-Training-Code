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

const int MOD = 1000000007;
 
ll calp(int x) {
    ll res = 1;
    while(x--) res = (res * 2) % MOD;
    return res;
}
 
void solve(){
    int n; string s;
    cin >> n >> s;
    int p = 0;
    for(char c : s) if(c=='?') p++;
    if(n==1){
        cout << calp(p) % MOD << endl;
        return;
    }
    int x = (s[0]=='?'), y = (s[n-1]=='?');
    ll r = calp(p - x - y), E, I;
    if(x==0 && y==0){
        if(s[0]==s[n-1]) { E = r; I = 0; }
        else { E = 0; I = r; }
    }
    else if(x+y==1){ E = r; I = r; }
    else { E = (2 * r) % MOD; I = (2 * r) % MOD; }
    ll ans = (((n-2LL) % MOD * E) % MOD + 2LL * I) % MOD;
    cout << ans % MOD << endl;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin >> T;
    while(T--){solve();}
    
    akitama;
}
