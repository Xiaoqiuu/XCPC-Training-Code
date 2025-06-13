#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
    long long N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<pair<int, int>> blocks; // 用于存储1块的起始和结束位置

    // 找到所有的1块
    for (int i = 0; i < N;) {
        if (S[i] == '1') {
            int start = i;
            // 继续找到这个块的结束位置
            while (i < N && S[i] == '1') {
                i++;
            }
            int end = i - 1; // 第一个0或字符串末尾之前的节点
            blocks.emplace_back(start, end);
        } else {
            i++;
        }
    }

    // 获取 K-1 和 K 的块
    int idx1 = K - 1; // K-1 块的索引
    int idx2 = K;     // K 块的索引

    // 构造新的字符串
    string result = S;

    // 替换 K-1 和 K 块中的内容
    int l1 = blocks[idx1].first; // K-1 块的开始位置
    int r1 = blocks[idx1].second; // K-1 块的结束位置
    int l2 = blocks[idx2].first; // K 块的开始位置
    int r2 = blocks[idx2].second; // K 块的结束位置

    // 创建新字符串
    // 部分1
    result.replace(l1, r1 - l1 + 1, string(r1 - l1 + 1, '1'));
    // 向上移动 K 块的内容
    result.replace(r1 + 1, r2 - l2 + 1, string(r2 - l2 + 1, '1'));
    // 放置0
    result.replace(r1 + 1 + (r2 - l2 + 1), N - (r2 + 1), S.substr(r2 + 1));
    
    // 输出结果
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
