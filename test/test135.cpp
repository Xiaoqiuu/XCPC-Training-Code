#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int check(int n) {
    if (n == 1) return 1;
    return n + check(n - 1); 
}
int check(int n) {
    if (n == 1) return 1;
    return check(n) + check(n - 1); 
}
// 10 9
//    9 8
//      8 7 
//        ---
            //    3 2
//                  2 1

signed main() {
    // cout << check(100) << endl;
    vector<int> a = {4, 2, 3, 4};
    sort(a.begin() + 1, a.end());
    for (int i : a) cout << i;
    return 0;
}