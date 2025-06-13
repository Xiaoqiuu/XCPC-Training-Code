#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<pair<int, int>> p;
        int i=1, j=1;
        p.emplace_back(i,j);
        for(char c:s){
            if(c=='D') i++;
            else j++;
            p.emplace_back(i,j);
        }
        vector<vector<ll>> a(n+1, vector<ll>(m+1));
        vector<vector<bool>> path(n+1, vector<bool>(m+1, false));
        for(auto &[x, y]:p) path[x][y]=true;
        for(int r=1;r<=n;r++) {
            for(int c=1;c<=m;c++) {
                cin >> a[r][c];
                if(path[r][c]) a[r][c]=0;
            }
        }
        vector<ll> sr(n+1, 0), sc(m+1, 0);
        for(int r=1;r<=n;r++) {
            for(int c=1;c<=m;c++) {
                if(!path[r][c]){
                    sr[r] += a[r][c];
                    sc[c] += a[r][c];
                }
            }
        }
        vector<ll> br(n+1, 0), bc(m+1, 0);
        for(auto &[x, y]:p){
            br[x] = 0;
        }
        vector<ll> remr(n+1, 0), remc(m+1, 0);
        for(int r=1;r<=n;r++) remr[r] = -sr[r];
        for(int c=1;c<=m;c++) remc[c] = -sc[c];
        for(int idx=0; idx<(int)p.size()-1; idx++){
            auto &[x, y] = p[idx];
            br[x] = remr[x];
            remc[y] -= br[x];
            remr[x] =0;
        }
        auto &[lx, ly] = p.back();
        br[lx] = remr[lx];
        remc[ly] -= br[lx];
        // Optional: check remc[ly]==0
        vector<vector<ll>> b(n+1, vector<ll>(m+1));
        for(auto &[x, y]:p){
            b[x][y] = br[x];
        }
        for(int r=1;r<=n;r++){
            for(int c=1;c<=m;c++){
                if(path[r][c]){
                    cout << b[r][c] << (c==m? '\n':' ');
                }
                else{
                    cout << a[r][c] << (c==m? '\n':' ');
                }
            }
        }
    }
}
