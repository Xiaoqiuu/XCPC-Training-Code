
#include <bits/stdc++.h>
using namespace std;

signed main() {
    unordered_map<string, int> um;
    um["Tuesday"] = 2;
    um["Sunday"] = 7;
    /*
        遍历um 输出内容：
        Sunday = 7
        Tuesday = 2
    */
    for (auto i : um) cout << i.first << " = " << i.second << '\n';
    return 0;
}