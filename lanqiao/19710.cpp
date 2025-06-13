//19710 2024Shengsai R
//赛时做法
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
char a[10000];
char b[10000];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long double m, n;cin >> m >> n;
    for (int i = 1; i <= (int)m; i++)
    n *= 2;
    n - (int)n <= 0.5? n = (int)n : n = (int)n + 1;
    //cout
    cout<< n << "\n";
    return 0;
}

//普通的高精度模板（手搓）
char high_precision(char a[], char b[]) {
    ll a_len = strlen(a);
    ll b_len = strlen(b);
    ll max_len = (a_len > b_len)? a_len : b_len;
    char res[max_len];
    for (int i = max_len - 1; i >= 0; -- i) {
    }
    return res;
}
