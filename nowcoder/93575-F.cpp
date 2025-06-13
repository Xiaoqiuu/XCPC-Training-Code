//o2优化
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#define akitama return 0
#include <iostream>  
#include <vector>  
#include <string>  
#include <unordered_map> 
using ll = long long;  
using str = std::string;  
using namespace std; 
 
//失效fuction部分匹配表
void build_fuc(const str& patt, vector<int>& table) {  
    int m = patt.size();  
    int j = 0;  
    table[0] = -1;  
    for (int i = 1; i < m; ++i) {  
        while (j >= 0 && patt[i] != patt[j + 1]) {  
            j = table[j];  
        }  
        if (patt[i] == patt[j + 1]) {  
            ++j;  
        }  
        table[i] = j;  
    }  
}  
int kmp(const str& text, const str& patt, int k) {  
    int n = text.size();  
    int m = patt.size();  
    vector<int> table(m);  
    build_fuc(patt, table);  
  
    int count = 0;  
    int j = -1;  
    for (int i = 0; i < n; ++i) {  
        while (j >= 0 && text[i] != patt[j + 1]) {  
            j = table[j];  
        }  
        if (text[i] == patt[j + 1]) {  
            ++j;  
        }  
        if (j == m - 1) {  
            ++count;  
            if (count == k) {  
                return i - m + 1;  
            }  
            j = table[j]; 
        }  
    }  
    return -1;  
}  
  
int main() {  
    int n, q;cin >> n >> q;  
    str S;cin >> S;  
    //unordered_map<str, vector<int>> preprocessResults;  
    for (int i = 0; i < q; ++i) {  
        str T;  
        int k;  cin >> T >> k;  
        ll ans = kmp(S, T, k);  
        cout << ans << endl;  
    }  
    akitama;  
}