#include <bits/stdc++.h>

using namespace std;

#define akitama return 0
#define ll long long 

void solve() {
    
    int t; cin >> t;
    vector<string> name(t);
    vector<int> v(t);
    for (int i = 0; i < t; i++) {
        cin >> name[i] >> v[i];
    }


    int tar = -1, tmp = -1;
    for (int i = 0; i < t; i++) {
        if(tmp < v[i]) {
            tmp = v[i];
            tar = i;
        }
    }
    cout << name[tar] << endl;

}

signed main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    while (_) {
        solve();
        _--;
    }
    akitama;
}c