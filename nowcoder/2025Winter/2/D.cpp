#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

#define akitama return 0
#define ll long long
#define vi vector<int>

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vi> pos(26, vi());
    for(int i=0;i<n;i++) pos[s[i]-'a'].push_back(i);
    int l=1, r=n, ans=0;
    while(l <= r){
        int m = l + (r - l)/2;
        bool f=false;
        vi freq(26, 0);
        for(int i=0;i<m;i++) freq[s[i]-'a']++;
        for(int p=0; p +m <=n && !f; p++){
            if(p >0){
                freq[s[p-1]-'a']--;
                freq[s[p+m-1]-'a']++;
            }
            bool ok=false;
            for(int c=0;c<26;c++) {
                if(freq[c] >0){
                    if(!pos[c].empty()){
                        if(pos[c][0] <p || pos[c].back() >= p +m){
                            ok=true;
                            break;
                        }
                    }
                }
            }
            if(ok){
                f=true;
                break;
            }
        }
        if(f){
            ans=m;
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(); 
    return 0;
}
