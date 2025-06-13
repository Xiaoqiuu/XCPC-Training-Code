#include <iostream>
#include <vector>
using namespace std;

#define akitama return 0
#define ll long long int

signed main() {
    vector<ll> pre(10);
    vector<ll> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ll sum = 0;
    for (int i = 0; i < 10; ++ i) {
        sum += a[i];
        pre[i] = sum;
    }
    for (int i = 1; i < 11; ++ i) { cout << "Sum"<<i<<" : " << pre[i-1] << endl; }
    cout << "The index : 6 is : " << pre[5] - pre[4] << endl;
    cout << "The sum from 1 to 6 is : " << pre[5] << endl;
    cout << "The sum from 4 to 9 is : " << pre[8] - pre[2] << endl;

    akitama;
}