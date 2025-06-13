#include <iostream>
#include <algorithm>
using namespace std;
#define akitama return 0
#define vi vector<int>
void solve(){
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    cout << max({x * a, y * b, z * c}) << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        solve();
    }
    akitama;
}