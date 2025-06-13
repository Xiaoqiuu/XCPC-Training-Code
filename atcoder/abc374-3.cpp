#include <iostream>
#include <algorithm>
#include <cstring>
#define akitama return 0
using namespace std;
using ll = long long;

ll count(ll a[], bool flag[]) {
    ll max = 0,sum_a = 0,sum_b = 0;
    for(int k = 1;k<a.length();k++){//整体进1
        flag[k] = false;
        for(int q= k;q >= a.length();q++) {
            for(int i= q + 1;i<=a.length();i++) {
                flag[i] = false;
                if(flag[i] == true) sum_a += a[i];
                else sum_b += a[i];
                sum_a < sum_b? max = sum_b : max = sum_a;
                flag[i] == true;
            }
            flag[q] = false;
        }

        // for(int j=1;j<strlen(a);j++) {
        //     // A组都是true
        //     if(flag[j]== true) sum_a += a[j];
        //     else sum_b += a[j];
        // }
    }
        return max;
    }
int main() 
{
    
    //N个公寓 第i个公寓的人数为K[i]
    //人数分为两组 使得某一种组合下两组中的一组人数最多
    int n;cin >> n;
    ll a[n + 1];
    for(int i=1;i<n;i++) cin >> a[i];
    bool flag[n + 1];
    memset(flag,false,sizeof(flag));
    ll ans = count(a,flag);
    cout << ans << endl;
    
    akitama;
}