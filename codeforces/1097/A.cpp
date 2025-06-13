#include <iostream>
using namespace std;

#define akitama return 0
/* AKITAMA 2025.3.19 */
#define ll long long int
#define st string

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    st s; cin >> s;
    st a, b, c, d, e; cin >> a >> b >> c >> d >> e;
    bool ans = false;
    if(s[0] == a[0] || s[0] == b[0] || s[0] == c[0] || s[0] == d[0] || s[0] == e[0]) ans = true;
    if(s[1] == a[1] || s[1] == b[1] || s[1] == c[1] || s[1] == d[1] || s[1] == e[1]) ans = true;
    
    if(ans)cout << "YES\n";
    else cout << "NO\n";
    akitama;
}