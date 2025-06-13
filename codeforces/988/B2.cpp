#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int a = 0, b = 0;
    int n_1;cin >> n_1;
    int target = n_1 - 2;
    vector<int, int> vec;
    for(int i = 1;i <= n_1;i++)
        for(int j = 1;j <= n_1;j++)
            if(i*j == target) {
                vec.push_back(i, j);
            }
    int num[n_1];
    for(int i = 0; i < n_1; i++)
        cin >> num[i];
    for(auto x : vec) {
        vec[x].first 
    }
    //sort(num, num + n_1);
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while(t--) {
        solve();
    }
    return 0;
} 