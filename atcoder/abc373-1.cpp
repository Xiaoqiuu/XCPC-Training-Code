#include <iostream>
#include <cstring>
#define akitama return 0

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int ans = 0;
    for (int i = 1; i <= 12; ++ i) {
        char ch[104];
        cin >> ch;
        if (strlen(ch) == i) {
            ans ++;
        }
    }
    cout << ans << '\n';
    akitama;
}