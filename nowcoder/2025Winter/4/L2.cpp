#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define akitama return 0
#define MOD 1000000007
#define REP(i,a,b) for(int i=a;i<=b;i++)

void solve(){
    int n,q;cin>>n>>q;
    vi A(n+1),B(n+1);
    REP(i,1,n)cin>>A[i];
    REP(i,1,n)cin>>B[i];
    int K=32;
    vvi PA(K,vi(n+1,0)),PB(K,vi(n+1,0)),IA(K,vi(n+1,0));
    vvl F0(K,vl(n+1,0)),F1(K,vl(n+1,0));
    REP(k,0,K-1)
        REP(i,1,n){
            int a=(A[i]>>k)&1, b=(B[i]>>k)&1;
            PA[k][i]=PA[k][i-1]+a;
            PB[k][i]=PB[k][i-1]+b;
            F0[k][i]=F0[k][i-1]+(a==0?PB[k][i-1]:0);
            F1[k][i]=F1[k][i-1]+(a==1?PB[k][i-1]:0);
            IA[k][i]=IA[k][i-1]+(a==1?i:0);
    }
    while(q--){
    int l,r;cin>>l>>r;
    ll ans=0;
    REP(k,0,K-1){
    int tot=PA[k][r]-PA[k][l-1];
    int z=(r-l+1)-tot;
    int pb=PB[k][r];
    int ia=IA[k][r];
    ll s0=F0[k][r]-F0[k][l-1],s1=F1[k][r]-F1[k][l-1];
    int si=IA[k][r]-IA[k][l-1];

    ll part=((ll)pb*z-s0+((ll)(r+1)*tot-si-(ll)pb*tot+s1))%MOD;
    if(part<0)part+=MOD;
    ans=(ans+part*((1LL<<k)%MOD))%MOD;
    }
    cout<<ans<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--)solve(); akitama;
}