#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define ll long long int
#define vi vector<int> 
#define vll vector<ll> 
#define akitama return 0

ll ans = 0;

signed main() {
    string s = "1";
    for (int i = 2; i<= 2025; ++ i) {
        s += to_string(i);
    }

    vll dp = {0, 0, 0, 0};
    
    for (int i = 0; i< s.size(); ++ i) {
        if (s[i] == '2') {
            dp[0] ++;
            dp[2] += dp[1];
        } else if(s[i] == '0') {
            dp[1] += dp[0];
        } else if (s[i] == '5') {
            dp[3] += dp[2];
        }
    }
    for (int i = 0; i < dp.size(); ++ i) cout << dp[i] << " ";
    cout << s << endl;
    cout << dp[3] << endl;

    akitama;
}