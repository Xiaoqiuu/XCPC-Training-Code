#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define akitama return 0

void solve() {
    int num; cin >> num;
    vector<ll> a(num), b(num);
    ll sumA = 0, sumB = 0;
    for(int i=0;i<num;i++) {
        cin >> a[i];
        sumA += a[i];
    }
    for(int i=0;i<num;i++) {
        cin >> b[i];
        sumB += b[i];
    }
    for(int i=0;i<num;i++) {
        if(abs(sumA - sumB)%2==1) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        return;
    }
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
