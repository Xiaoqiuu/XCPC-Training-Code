#include <iostream>
#include <cstring>
#include <cmath>
#define akitama return 0

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    char ch[104];cin >> ch;
    ll ans = 0;int l_a = 0, tmp = 0;
    for (int n = 0; n < strlen(ch); n ++) {
        if(ch[n] == 'A')
        {
            l_a = n;//A的位置
            tmp = n;
            break;
        }
    }
    for (char a = 'B'; a <= 'Z'; a ++ )
    for (int n = 0; n < strlen(ch); n ++) {
        if(a == ch[n]) {
        ans += abs(n - tmp);
        tmp = n;
        break;
        }
    }
    cout << ans << endl;
    akitama;
}