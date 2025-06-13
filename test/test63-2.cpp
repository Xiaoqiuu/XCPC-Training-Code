#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 9;    //pi的范围为1e6 
int a[N],prefix[N],nex[N],b[N];
signed main(){
    int n; cin >> n;
    int ans = 1e18;
    int max_ = 0;
    for(int i = 1; i <= n; i++){
        int w,p; cin >> w >> p;
        if(a[p] == 0) a[p] = w;
        else a[p] += w;
        max_ = max(max_,p);    //保存石头最大的位置 
    }
    int z = 0;
    for(int i = 1;i <= max_; i++){    //b数组离散 
        if(a[i] != 0) b[++z] = i; 
    }
    int s = 0;
    for(int i = 1; i <= z; i++){    //i前面的石头到 i位置和 
        prefix[i] = prefix[i - 1] + s * (b[i] - b[i - 1]);
        s += a[b[i]];
    }
    s = 0;
    for(int i = z; i >= 1; i--){    //i后面的石头到i的和 
        nex[i] = nex[i + 1] + s * (b[i + 1] - b[i]);
        s += a[b[i]];
    } 
    for(int i = 1;i <= z;i++){        
    ans = min(ans,prefix[i] + nex[i]);   
    }    
    cout << ans;
    return 0;
}