#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define akitama return 0

int main(){
    int n; cin >> n;
    bool f = 0;
    ll ans = 0;
    while (n--) {
        string s; cin >> s;
        if (s=="login") f = 1;
        else if (s=="private") {if(f==0)ans++;
        }else if (s=="logout") f = 0;
    }
    cout << ans << endl;
    akitama;
}
