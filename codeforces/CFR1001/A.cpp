#include <iostream>
#include <cstring>
using namespace std;

#define ll long long
#define akitama return 0

void solve() {
    char ch[1005];cin >> ch;
    int len = strlen(ch);
    int cnt = 0;
    for(int i=0;i<len;i++){
        if(ch[i] == '1'){
            cnt++;}}
            cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while(t--){
        solve();
    }
    akitama;
}