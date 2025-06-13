#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 2 || n == 3 || n == 4) {
        cout << -1 << '\n';
        return;
    }else if (n >= 8){
    vector<int> res;
        for (int i = (n%2 ==1? n : n - 1); i >= 1; i -= 2) res.push_back(i);
        res.push_back(8);
        for (int i = 2; i <= n; i += 2) 
        if (i == 8) continue;
        else res.push_back(i);
        for (int i = 0; i < n; ++i) cout << res[i] << " ";
        cout << '\n';
    } else{
        switch (n) {
        case 5: cout << "1 3 5 4 2" << endl;break;
        case 6: cout << "1 3 6 2 4 5" << '\n';break;
        case 7: cout << "1 7 3 6 2 4 5" << '\n';break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//-1
//11 9 7 3 5 1 8 2 4 6 10 12 14
//7 3 5 1 2 4 6 