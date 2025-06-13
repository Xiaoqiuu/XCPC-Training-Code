#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define akitama return 0

void solve() {
    int num; cin >> num;
    vector<ll> a(num), b(num);
    ll sum_a = 0, sum_b = 0, dec = 0;
    for(int i=0;i<num;i++) {
        cin >> a[i];
        sum_a += a[i];
    }
    for(int i=0;i<num;i++) {
        cin >> b[i];
        sum_b += b[i];
        if(b[i] > a[i]) dec += (b[i] - a[i]);
    }
    if(sum_a < sum_b){
        cout << "NO\n";
        return;
    }
    if(num ==2){
        ll k1 = max(b[0] - a[0], (ll)0);
        ll k2 = max(b[1] - a[1], (ll)0);
        if(a[1] >=k1 && a[0] >=k2){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        return;
    }
    ll max_ops = (num >2) ? ((sum_a - sum_b)/(num -2)) : 0;
    if(dec > max_ops){
        cout << "NO\n";
        return;
    }
    for(int i=0;i<num;i++){
        if(b[i] >a[i]){
            if(a[i] < (dec - (b[i] - a[i]))){
                cout << "NO\n";
                return;
            }
        }
        else{
            if(a[i] < dec){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        solve();
    }
    akitama;
}
