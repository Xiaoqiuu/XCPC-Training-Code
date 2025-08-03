// #include <iostream>
// #include <string>
// #include <stack>
// #include <queue>
#include <bits/stdc++.h>
#include <set>
#include <utility>
#include <algorithm>
#include <tuple>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int a[10];

signed main() {
    int n = 7;
    int a[10];
    // vector<int> a = {12, 3, 5, 344, 1, 44, 2};
    sort(a + 1, a + 3);
    for (int i : a) cout << i << " ";
    // pair<int, int> p1(1, 2);
    // pair<int, int> p2(3, 4);
    // pair<pair<int, int>, int> p3((100, 200),10);
    // vector<pair<int, int>> a;
    // for (int i = 0; i < n; ++ i) {
    //     cin >> a[i].first >> a[i].second;
    // }
    // // cin >> p3.first >> p3.second;
    // #define fi first
    // #define se second
    // // cout << p3.fi << " " << p3.se;
    // // cout << p1.fi << " " << p1.se;
}   