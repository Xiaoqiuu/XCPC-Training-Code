#include <bits/stdc++.h>
using namespace std;

#define akitama return 0
#define ll long long
#define vl vector<ll>

void study(vl v) {
    cout << "当前的序列为：" << endl;
    for(int i = 0;i < v.size();++ i) {
        cout << v[i] << " ";
    }
    cout << "\n输出完毕。" <<endl;
}

bool check(ll a, ll b,ll c,ll d) {
    if(a == b||a == c||a == d||b == c||b == d||c == d) return true;else return false;
}

void solve() {
    int num;cin >> num;
    vl v(num);
    for(int i = 0;i < num;++ i) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    study(v);

    ll tar_idx = -1;
    for(int i = 1;i < num;++ i) {
        if(v[i] == v[i - 1]) {
            tar_idx = i;
        }
    } if(tar_idx == -1) {
        cout << "-1" << endl;
        return;
    }

    ll tar = v[tar_idx];
    v.erase(v.begin() + tar_idx);
    study(v);
    v.erase(v.begin() + tar_idx - 1);
    study(v);
    for(int i = 1;i < v.size();++ i) {
        if(v[i] < v[i - 1] + tar * 2) {
            cout << tar << " " << tar << " " << v[i] << " " << v[i - 1] << endl;
            return;
        }
    }

    cout << "-1" << endl;

}
    

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;
    while(t --) {
        solve();
    }

    akitama;   
}