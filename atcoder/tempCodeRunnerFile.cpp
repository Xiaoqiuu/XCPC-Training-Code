#include <iostream>
#include <algorithm>
#include <cstring>
#define akitama return 0
using namespace std;

int main() 
{
    char s[1005], t[1005];
    cin >> s >> t;
    int s_len = strlen(s), t_len = strlen(t);
    int max_len = max(s_len, t_len);
    int ans = 0;
    for (int i = 0; i < max_len; i++) {
        if(s[i] <= 'z'&& s[i] >= 'A' && t[i] <= 'z' && t[i] >= 'A')
        if (s[i] == t[i]) continue;
        else ans = i + 1;
        else {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
    akitama;
}