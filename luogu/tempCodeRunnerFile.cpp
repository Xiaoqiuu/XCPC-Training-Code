//luogu P3654 First Step

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int count = 0,ans = 0;
    int R, C, K;cin >> R >> C >> K;
    //R rows, C columns K members
    char grid[R][C];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < R; i ++) {
        count = 0;
        for (int j = 0; j < C; j++) {
            if (grid[i][j] != '#') {
                count ++;
                if (count >= K) {
                    ans ++;
                }
            } else {
                count = 0;
            }
        }
    }
    for (int i = 0; i < C; i ++) {
        count = 0;
        for (int j = 0; j < R; j++) {
            if (grid[j][i] != '#') {
                count ++;
                if (count >= K) {
                    ans ++;
                }
            } else {
                count = 0;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}