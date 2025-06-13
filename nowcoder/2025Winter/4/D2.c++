#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vl>
#define akitama return 0

void solve(){
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    vi cnt_a(26, 0), cnt_b(26, 0);
    for(char c : a) cnt_a[c - 'a']++;
    for(char c : b) cnt_b[c - 'a']++;
    int cur_t = min(n, m), smwy = 0;
    for(int i = 0;i < 26;++ i) smwy += min(cnt_a[i],cnt_b[i]);
    int ans = cur_t - smwy;
    if(n != m){
    if(n > m){
        int ext = n - m, pr = ext >> 1, nat = 0;
        for(int i=0;i<26;i++){
        int x = cnt_a[i]-min(cnt_a[i],cnt_b[i]);
        nat += x/2;
        }
        ans += max(0, pr - nat);
    } else {
        int ext = m-n, pr = ext >> 1, nat = 0;
        for(int i = 0;i < 26;++ i){
        int x = cnt_b[i]-min(cnt_a[i], cnt_b[i]);
        nat += x >> 1;
        }
        ans += max(0, pr - nat);
    }
    }
    cout<< ans <<endl;
}

int main(){
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int T;cin>>T;
 while(T--){solve();} akitama;
}
