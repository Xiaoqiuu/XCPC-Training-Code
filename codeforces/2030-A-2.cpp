#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t; // 读取测试用例数量
    while (t--) {
        int n;
        cin >> n; // 读取数组长度
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // 读取数组元素
        }

        // 排序数组
        sort(a.begin(), a.end());

        // 初始化得分
        int score = 0;

        // 使用双指针策略
        int left = 0, right = n - 1;
        for (int i = 0; i < n; i++) {
            // 每次取最大值和最小值
            if (i % 2 == 0) {
                score += a[right]; // 取最大的
                right--; // 移动右指针
            } else {
                score -= a[left]; // 取最小的
                left++; // 移动左指针
            }
        }

        cout << score << endl; // 输出最大得分
    }
    return 0;
}
