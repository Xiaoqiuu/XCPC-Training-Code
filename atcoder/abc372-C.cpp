#include <iostream>
#include <algorithm>
//#include <queue>
//#include <vector>
#define akitama return 0
#define pq priority_queue
#define vec vector

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;
void kmp(string s, string p) {
    int n = s.length();
    int m = p.length();
    int next[m];
    getNext(p, next);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && p[j] != s[i]) {
            j = next[j-1];
        }
        if (p[j] == s[i]) {
            j++;
        }
        if (j == m) {
            cout << "pattern found at " << i-m+1 << endl;
            j = next[j-1];
        }
    }
}

void getNext(string p, int next[]) {
    int m = p.length();
    next[0] = -1;
    int j = 0;
    int k = -1;
    while (j < m-1) {
        if (k == -1 || p[j] == p[k]) {
            j++;
            k++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    ll ans = 0;
    //字符串S 和 子串P 
    //code here


    cout >> ans >> endl;
    akitama;
}