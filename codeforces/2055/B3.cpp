#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define akitama return 0

void solve() {
    int num; cin >> num;
    vector<ll> a(num), b(num);
    ll time = 0;
    for(int i=0;i<num;i++) {
        cin >> a[i];
    }
    for(int i=0;i<num;i++) {
        cin >> b[i];
    }
    while (time < num && a[time] >= b[time]) {
        time ++;
    }
    if(time == num) {
        cout << "YES" << endl;
        return;
    }
    for(int i=0;i<num;i++) {
        if (i!= time && a[i] - b[i] < b[time] - a[time]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
