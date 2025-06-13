#include <iostream>
#include <string>

using namespace std;

#define ll long long
#define akitama return 0
#define int long long

ll n, k; 
string s;

int check() {
    int check = -1;
    if(s[0] == 'g' && s[n-1] == 'n' && s[n-2] == 'i' && s[n-3] == 'j' && s[n-4] == 'n' && s[n-5] == 'a' && s[n-6] == 'n') check = 6;
    else if (s[0] == 'n' && s[1] == 'g' && s[n-1] == 'i' && s[n-2] == 'j' && s[n-3] == 'n' && s[n-4] == 'a' && s[n-5] == 'n') check = 5;
    else if (s[0] == 'i' && s[1] == 'n' && s[2] == 'g' && s[n-1] == 'n' && s[n-2] == 'a' && s[n-3] == 'n' && s[n-4] == 'j') check = 4;
    else if (s[0] == 'j' && s[1] == 'i' && s[2] == 'n' && s[3] == 'g' && s[n-1] == 'n' && s[n-2] == 'a' && s[n-3] == 'n') check = 3;
    else if (s[0] == 'n' && s[1] == 'j' && s[2] == 'i' && s[3] == 'n' && s[4] == 'g'&& s[n-1] == 'a' && s[n-2] == 'n') check = 2;
    else if (s[0] == 'a' && s[1] == 'n' && s[2] == 'j' && s[3] == 'i' && s[4] == 'n' && s[5] == 'g' && s[n-1] == 'n') check = 1;
    else if (s[0] == 'n' && s[1] == 'a' && s[2] == 'n' && s[3] == 'j' && s[4] == 'i' && s[5] == 'n' && s[6] == 'g') check = 0;
    else return -1;
    return check;
}

void solve() {
    cin >> n >> k;
    cin >> s;
    if(n < 7) { cout << 0 << endl; return;}
    ll ans = 0;
    for (int i = 0; i < n - 6; ++ i) {
        if(s[i] == 'n' && s[i+1] == 'a' && s[i+2] == 'n' && s[i+3] == 'j' && s[i+4] == 'i' && s[i+5] == 'n' && s[i+6] == 'g')
        ans ++;
    }
    
    if(check()<= k && check()>0){
        
        ans ++;
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _;
    cin >> _;
    while (_) {
        solve();
        _--;
    }

    akitama;
}