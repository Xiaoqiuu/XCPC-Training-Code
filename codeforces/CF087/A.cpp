#include <iostream>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    set<int> s;
    int num;cin >> num;
    if(num == 1) {
        int j;cin >> j;
        cout << 0 << endl;
    } else if(num == 2) {
        int a, b;cin >> a >> b;
        a > b? cout << 1 << endl : cout << 0 << endl;
    }
    else {
        int a[num + 1];
        for(int i = 1;i <= num; ++ i) {
            cin >> a[i];
            s.insert(a[i]);
        }
        int tar, tar_cnt = 0;
        int poppp = 0;
        for(auto it = s.begin(); it != s.end(); ++ it) {
            cout << "zhe set" << *it << " ";
            poppp ++;
            if(poppp == s.size() / 2 + 1) {
                tar = *it;
                break;
            }
        }

        for (int i = 1; i <= num; ++ i) {
            if(a[i] == tar) ++ tar_cnt;
        }
        cout << tar << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}