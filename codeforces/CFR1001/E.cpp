#include <bits/stdc++.h>
using namespace std;

static const int NMAX=400000;
int n,t;
int w[NMAX+5];
vector<int> adj[NMAX+5];
int inT[NMAX+5],outT[NMAX+5],T,par[NMAX+5];
vector<int> byval[NMAX+5];
int mx;
bool allmax;

void dfs(int u,int p){
    par[u]=p;
    inT[u]=++T;
    for(auto &v:adj[u])if(v!=p)dfs(v,u);
    outT[u]=T;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            adj[i].clear();
            byval[i].clear();
        }
        for(int i=1;i<=n;i++){
            cin>>w[i];
        }
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx,w[i]);
        }
        allmax=true;
        for(int i=1;i<=n;i++){
            if(w[i]<mx){allmax=false;break;}
        }
        if(allmax){
            cout<<0<<"\n";
            continue;
        }
        T=0;dfs(1,0);
        for(int i=1;i<=n;i++){
            byval[w[i]].push_back(inT[i]);
        }
        for(int i=1;i<=mx;i++){
            if(!byval[i].empty()) sort(byval[i].begin(),byval[i].end());
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(w[i]>=mx) continue;
            bool ok=true;
            for(int val=w[i]+1;val<mx;val++){
                if(!byval[val].empty()){
                    // we need all these in subtree(i)
                    // subtree(i) -> in[i]..out[i]
                    // if any node's inTime is outside in[i]..out[i], fail
                    // do a quick check via binary search
                    // if min or max inTime of that val is outside, fail
                    int lowPos=inT[i], highPos=outT[i];
                    auto &vec=byval[val];
                    if(vec.front()<lowPos || vec.back()>highPos){
                        ok=false; 
                        break;
                    }
                }
            }
            if(!ok) continue;
            // need at least one node with w=mx outside subtree(i)
            {
                auto &vec=byval[mx];
                int lowPos=inT[i], highPos=outT[i];
                // if all of them are inside [lowPos..highPos], fail
                // check if vec.front()>=lowPos && vec.back()<=highPos => fail
                // but we need to be sure absolutely all are inside
                if(!vec.empty()){
                    int lf=(int)(lower_bound(vec.begin(),vec.end(),lowPos)-vec.begin());
                    int rf=(int)(upper_bound(vec.begin(),vec.end(),highPos)-vec.begin());
                    // lf is index of first pos >= lowPos
                    // rf is index of first pos > highPos
                    // if (rf-lf)==(int)vec.size(), means all are in subtree
                    if(rf-lf==(int)vec.size()){
                        ok=false;
                    }
                }
            }
            if(ok){ans=i;break;}
        }
        if(!ans) cout<<0<<"\n";
        else cout<<ans<<"\n";
    }
    return 0;
}
