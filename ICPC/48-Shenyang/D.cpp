#include <iostream>
#include <cstring>
using namespace std;
using i64 = long long;

void solve() {
    char s[6];
    int t = 0, d = 0;
    scanf("%s", s);
    int end = strlen(s) == 5 ? 5 : strlen(s) - 1;
    for (int i = 0; i < end; i++) {
        t += s[i] == 'T';
        d += s[i] == 'D';
    }
    puts(t > d? "T1" : "DRX");
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}