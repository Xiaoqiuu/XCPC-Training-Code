#include <iostream>
#include <cmath>
#define akitama return 0;
using namespace std;
using ll = long long;
int main() {
    int t;cin >> t;
    ll ans[t + 1];
    for (int i = 1;i <= t; ++ i) {
        ll n_m, sum = 0;cin >> n_m;//矩阵宽度
        int mount[n_m + 1][n_m + 1];
        for (int j = 1;j <= n_m; ++ j) {
            for (int k = 1; k <= n_m; ++ k)
            cin >> mount[j][k];
        }
        //单独判断 1 和 n_m
        if(mount[1][1] < 0) sum += abs(mount[1][1]);
        if(mount[n_m][n_m] < 0 ) sum += abs(mount[n_m][n_m]);
        int r = 1, w = 2;
        for (int j = 2;j <= n_m; ++ j) {
            int tmp = 0;
            if(r == 0 || w == 0 || r > n_m || w > n_m)break;
            for (int time = 0; time < j; ++ time) {
                if(r + time == 0 || w - time == 0 || r + time > n_m || w - time > n_m)break;
                if(mount[r + time][w - time] < 0 && mount[r + time][w - time] < tmp) {
                    sum += abs(mount[r + time][w - time]);
                    tmp = mount[r + time][w - time];
                }
            }
            w++;
        }
        r = 2, w = n_m;
        for (int j = n_m;j > 0; -- j) {
            int tmp = 0;
            if(r == 0 || w == 0 || r > n_m || w > n_m)break;
            for (int time = 0; time < j; ++ time) {
                if(r + time == 0 || w - time == 0 || r + time > n_m || w - time > n_m)break;
                if(mount[r + time][w - time] < 0 && mount[r + time][w - time] < tmp){
                    sum += abs(mount[r + time][w - time]);
                    tmp = mount[r + time][w - time];
                }
            }
            r++;
        }
        ans[i] = sum;
    }
    for (int i = 1;i <= t; ++ i)cout << ans[i] << endl;
    akitama;
}