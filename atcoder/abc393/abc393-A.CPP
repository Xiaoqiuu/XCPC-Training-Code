#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define akitama return 0

signed main(){
    char a[5], b[5];
    cin >> a >> b;
    int ans = 0;
    if(a[0] == 'f' && b[0] == 'f') ans = 4;
    if(a[0] == 'f' && b[0] == 's') ans = 3;
    if(a[0] == 's' && b[0] == 'f') ans = 2;
    if(a[0] == 's' && b[0] == 's') ans = 1;
    cout << ans << endl;

    akitama;
}