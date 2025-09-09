#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int T; if(!(cin>>T))return 0;
    while(T--){
        int n,m,q;cin>>n>>m>>q;
        vector<ll>a(n),b(m);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;
        sort(a.rbegin(),a.rend());sort(b.rbegin(),b.rend());
        vector<ll> pa(n+1),pb(m+1);
        for(int i=0;i<n;i++) pa[i+1]=pa[i]+a[i];
        for(int i=0;i<m;i++) pb[i+1]=pb[i]+b[i];
        while(q--){
            ll x,y,z;cin>>x>>y>>z;
            ll L=max(0LL,z-min<ll>(y,m)), R=min<ll>({(ll)n,(ll)x,z});
            ll lo=L,hi=R;
            auto ok=[&](ll t){
                ll i=z-t-1;
                if(i<0) return true;
                return a[t-1]>b[i];
            };
            while(lo<hi){
                ll md=(lo+hi+1)>>1;
                if(ok(md)) lo=md; else hi=md-1;
            }
            cout<<pa[lo]+pb[z-lo]<<"\n";
        }
    }
    return 0;
}
