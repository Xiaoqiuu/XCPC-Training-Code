#include <iostream>
#include <algorithm>
#include <cstring>
//#include <queue>
//#include <vector>
#define akitama return 0
#define pq priority_queue
#define vec vector

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    ll ans = 0;
    ll N;cin >> N;
    int C[N][N];
    memset(C, 0, sizeof(C));
    //code here
    for (int n = 0; n < N; n++) { // loop over n from 0 to N-1 (inclusive)
        C[n][0] = 1;
        C[n][n] = 1;
        for (int k = 1; k < n; k++) // loop over k from 1 to n-1 (inclusive)
        {
            C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
        }
        
    }
    for (int i = 0; i < N; i++) { // loop over i from 0 to N-1 (inclusive)
        for (int j = 0; j < N; j++) { // loop over j from 0 to N-1 (inclusive)
            cout <<  C[i][j] << '\t';
        }
        cout << '\n';
    }

    akitama;
}
