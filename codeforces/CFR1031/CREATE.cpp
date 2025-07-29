#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

// 生成随机整数在[min, max]范围内
int random_int(int min, int max) {
    static mt19937 rng(time(nullptr));
    uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

// 生成测试用例
void generate_test_case(int n, ofstream &out) {
    // 创建所有牌(1到2n)
    vector<int> all_cards(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        all_cards[i] = i + 1;
    }
    
    // 随机打乱所有牌
    shuffle(all_cards.begin(), all_cards.end(), mt19937(time(nullptr)));
    
    // 将牌分成玩家和庄家的手牌
    vector<int> player_hand(all_cards.begin(), all_cards.begin() + n);
    vector<int> dealer_hand(all_cards.begin() + n, all_cards.end());
    
    // 输出测试用例到文件
    out<< n << "\n";
    for (int card : player_hand) {
        out << card << " ";
    }
    out << "\n";
    for (int card : dealer_hand) {
        out << card << " ";
    }
    out << "\n";
}

int main() {
    // 打开文件用于写入测试数据
    ofstream out("test.in");
    if (!out.is_open()) {
        cerr << "无法打开文件 test.in 进行写入" << endl;
        return 1;
    }

    // 设置随机种子
    mt19937 rng(time(nullptr));
    
    // 决定测试用例的数量和配置
    int num_regular_test_cases = 10;  // 常规测试用例数量
    vector<int> test_case_ns = {4, 8, 12, 24, 588, 42, 33000, 5000, 100, 49998};  // 不同大小的n
    bool include_large_test_case = true;  // 是否包含大测试用例
    int large_test_case_n = 200000;       // 大测试用例的n值
    
    // 计算总测试用例数量
    int total_test_cases = num_regular_test_cases + (include_large_test_case ? 1 : 0);
    
    // 首先输出测试用例的总数
    out << total_test_cases << "\n";
    
    // 生成常规测试用例
    for (int i = 0; i < num_regular_test_cases; ++i) {
        int n = test_case_ns[i % test_case_ns.size()];  // 循环使用不同的n值
        generate_test_case(n, out);
    }
    
    // 生成大测试用例（如果启用）
    if (include_large_test_case) {
        generate_test_case(large_test_case_n, out);
    }
    
    // 关闭文件
    out.close();
    
    cout << "测试数据已成功写入 test.in 文件，共 " << total_test_cases << " 个测试用例" << endl;
    
    return 0;
}