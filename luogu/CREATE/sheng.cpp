/*
 * @Author: Xiaoqiuu xiaoqiuuu@gmail.com
 * @Date: 2025-07-26 03:50:59
 * @LastEditors: Xiaoqiuu xiaoqiuuu@gmail.com
 * @LastEditTime: 2025-07-26 03:51:02
 * @FilePath: /workspace/luogu/CREATE/sheng.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int Q = 10000; // 操作总数
    set<int> inserted;
    vector<pair<int, int>> ops;

    // 先生成 5000 条插入操作（包括一部分重复插入）
    for (int i = 0; i < 5000; ++i) {
        int x = rand() % 1000000000 + 1;
        ops.push_back({1, x});
        inserted.insert(x);
        // 每隔一段重复插入一次
        if (i % 700 == 0) ops.push_back({1, x});
    }

    // 从插入的数中构造一些删除操作
    vector<int> vals(inserted.begin(), inserted.end());
    int N = vals.size();

    for (int i = 0; i < 2500; ++i) {
        int x = vals[i % N];
        ops.push_back({2, x});
    }

    // 随机生成一些不在集合中的删除操作
    for (int i = 0; i < 2500; ++i) {
        int x;
        do {
            x = rand() % 1000000000 + 1;
        } while (inserted.count(x));
        ops.push_back({2, x});
    }

    // 打乱顺序（可选）
    // random_shuffle(ops.begin(), ops.end());

    // 输出测试数据
    cout << ops.size() << "\n";
    for (auto [op, x] : ops) {
        cout << op << " " << x << "\n";
    }

    return 0;
}
