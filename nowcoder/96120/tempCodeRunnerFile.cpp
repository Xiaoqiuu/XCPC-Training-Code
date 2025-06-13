#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <vector>
using namespace std;
#define akitama return 0
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define usi unordered_set<int>
int check(const vector<int>& nums, int k) {
    usi numSet(nums.begin(), nums.end());
    int max_length = 0;

    for (const int& num : numSet) {
        // 只从当前段的最小数开始
        if (numSet.count(num - 1) == 0) { 
            int current = num;
            int current_len = 1;
            int remaining_k = k;

            // 计算当前数字的连续长度
            while (true) {
                if (numSet.count(current + 1)) {
                    current++;
                    current_len++;
                } 
                else if (numSet.count(current + 1) == 0 && remaining_k > 0) {
                    // 使用补丁来补齐当前缺失的下一个数字
                    remaining_k--;
                    current++;
                    current_len++;
                } 
                else {
                    // 没有补丁可用
                    break;
                }
            }
            max_length = max(max_length, current_len);
        }        
    }

    return max_length;
}
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    ll ans =check(nums,k);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    akitama;
}