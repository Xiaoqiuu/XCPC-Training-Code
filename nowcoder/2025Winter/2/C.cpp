#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

#define akitama return 0
#define ll long long
#define vi vector<int>

// void solve(){

// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        ll n, m;
        cin >> n >> m;
        if(n == m){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if(n == m + 1){
            for(int i = 0; i < m - 1; i++) cout << 'a';
            cout << "bb\n";
            continue;
        }
        for(int i = 0; i < m; i++){
            cout << 'a';
        }
        cout << 'b' << 'a';
        for(long long i = 0; i < n - (m + 2); i++){
            cout << 'c';
        }
        cout << "\n";
    }
    return 0;
}
