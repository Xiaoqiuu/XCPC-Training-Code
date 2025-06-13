#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using ll = long long;
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 1; i < n; ++i) {
        if (abs(a[i] - a[i-1]) >= a[i] * a[i-1]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}

/*
int main() {
    ll n;cin >> n;
    ll a[n];
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++ i) {
        for(int j = 0; j < n; ++ j) {
            if(abs(a[i] - a[j]) < a[i] * a[j]) continue;
            else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}*/