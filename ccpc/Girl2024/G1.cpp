#include <iostream>
#include <cstring>
using namespace std;
#define akitama return 0
using ll = long long;
int main() {
    char ch[1000008];
    cin >> ch;
    int n = strlen(ch);
    ll ans = 0, c = 0, p = 0;
    for (int i = 0; i < n; i++) {
        if (ch[i] == 'C') c++;
        else if (ch[i] == 'P') p++;
    } 
    if ( c > 3 && p > 0) {
            c -= 3;
            p --;
            ans ++;
        while(c>0 && p > 0) {
        c-= 2;
        p --;
        if (c < 0 || p < 0) break;
        ans ++; 
        }
    } else ans = 0;
    printf("%lld\n", ans);
    akitama;
}