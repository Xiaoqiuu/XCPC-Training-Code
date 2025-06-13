#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
using ll = long long;

// double check(vector<int>& nums) {
//     sort(nums.begin(), nums.end());

//     vector<int> re_arr;
//     int n = nums.size();
//     for (int i = 0; i < (n + 1) / 2; ++i) {
//         re_arr.push_back(nums[i]);
//         if (i != n - 1 - i) { 
//             re_arr.push_back(nums[n - 1 - i]);
//         }
//     }
    
//     double total_sum = 0;
//     for (size_t i = 0; i < re_arr.size() - 1; ++i) {
//         total_sum += re_arr[i] + re_arr[i + 1];
//     }

//     return total_sum;
// }

void solve() {
    int n;
    cin >> n;
    switch(n) {
        case 1: {
            int tmp;
            cin >> tmp;
            cout << "0.00" << endl;
            break;
        }
        case 2: {
            int a, b;
            cin >> a >> b; 
            cout << fixed << setprecision(2) << (a + b) / 2.0 << endl;
            break;
        }
        default: {
            // vector<int> nums(n);
            // for (int i = 0; i < n; ++i) {
            //     cin >> nums[i];
            // }
            // double res = check(nums);
            // cout << fixed << setprecision(2) << (res*n)/2.0 << endl;
            // break;
            int a[n];
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            sort(a, a + n,[](int a, int b){return a > b;});
            double res = 0;
            for(int i = 1;i < n - 1; ++ i ){
                res += (a[i] + a[i - 1]);
            }
            res += a[n - 1] + a[0];
            cout << fixed << setprecision(2) << res * n / (2.0 * n) << endl;
        }
    }   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
