#include <iostream>
#include <unordered_map>
#include <cstring>
#define akitama return 0;
using namespace std;
using ld = long double;
using ll = long long;
int main(){
    unordered_map<int, string> mp;
    mp[10202] = "Hangqi";
    mp[67382] = "Akitama";
    mp[20091] = "Pencil_box";
    mp[99999] = "CCPC";
    mp[70] = "WIN!";
    cout << mp[10202] << " will attend : " << mp[99999] << endl;
    mp.erase(10202);
    cout << "现在对unordered_map 进行遍历操作。" << endl;
    for (auto kv : mp) {
        cout << kv.first << "->" << kv.second << endl;
    }
    cout <<"现在进行第二次遍历操作。本次遍历将会对哈希表的内容进行一些变换。"<< endl;
    mp[80800] = "Server";
    mp[87654] = "Dalian University of Foreign Languaues";
    mp.erase(67382);
    mp[1] = "Akitama";
    for(unordered_map<int, string>::iterator it = mp.begin(); it != mp.end(); it ++) {
        cout << it->first << "->" << it->second << endl;
    }
    akitama;
}

void dfs(int a, int b) {
    ll dp[a][b];
    memset(dp, 0, sizeof(dp));
    for (int i = 0;i < b; ++ i) {
        dp[0][i] = 1;
    }
    if (a == 0) {
        cout << dp[0][0] << endl;
        return;
    }
    for (int i = 1;i < a; ++ i) {
        for (int j = 0;j < b; ++ j) {
            dp[i][j] = dp[i-1][j];
            if (j > 0) {
                dp[i][j] += dp[i-1][j-1];
            }
            if (j < b-1) {
                dp[i][j] += dp[i-1][j+1];
            }
        }
    }
}