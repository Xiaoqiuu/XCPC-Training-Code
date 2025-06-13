//WRitten By Akitama
#include <iostream>
#include <algorithm>
#include <vector>
#define akitama return 0;
using ll =long long;
using namespace std;
int main() {
    int n;cin >> n;
    vector<ll> a(n);
    vector<ll> b(n - 1);
    //a为玩具大小，b为箱子大小，输入
    for(int i=0;i<n;i++){
        cin >> a[i];
        }
    for(int i=0;i<n - 1;i++){
        cin >> b[i];
    }
    //排序
    sort(a.begin(),a.end());
    //从最大的玩具开始一个一个找剩余最大的箱子匹配 把剩余空间存进箱子中
    for(int i=n-1;i>=1;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(a[i] <= b[j])
            {
                b[j] -= a[i];
            }
        }
    }
    cout << lower_bound(b.begin(),b.end(),a[0]) << endl;
    akitama;
}