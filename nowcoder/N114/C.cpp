#include <bits/stdc++.h>
using namespace std;

#define akitama return 0
#define ll long long int
signed main(){
    int n, x; cin >> n >> x;
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n;++ i) {
        cin >> a[i];
    }

    unordered_map<int> vis;
    int cur = x;
    bool flag = false;

    while (1) {
        if (vis.count(cur)) {
            flag = true;
            break;
        }
        vis.insert(cur);

        int next = a[cur];
        if (next == cur) {
            break;
        }
        cur  = next;
    }

    cout << (flag? "Yes" : "No") << endl;
    

    akitama;
}