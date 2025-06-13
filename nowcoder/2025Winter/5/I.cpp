#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back
#define sl set<ll>
#define akitama return 0
//Akitama 2.8
#define lowbit(x) ((x)&(-x))
int odd(int x){ while((x&1)==0)x/=2; return x; }
bool bfs(int n,int m){
    int s=odd(n),t=odd(m);
    queue<int> qu;
    unordered_set<int> vis;
    qu.push(s); vis.insert(s);
    while(!qu.empty()){
        int c=qu.front(); qu.pop();
        if(c==t)return true;
        for(int a=0;;a++){
        ll prod=(ll)c*(1LL<<a);
        ll sq=floor(sqrt((long double)prod));
        if(sq>c) break;
        int nx=odd((int)sq);
        if(!vis.count(nx)){vis.insert(nx); qu.push(nx);}
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;cin>>_;
    while(_--){
        int n,m;cin>>n>>m;
        if(n==m){cout<<"Yes\n"; continue;}
        if(n==0){cout<<(m==0?"Yes":"No")<<"\n"; continue;}
        if(m==0){cout<<"No\n"; continue;}
        cout<<(bfs(n,m)?"Yes":"No")<<"\n";
    }
    akitama;
}