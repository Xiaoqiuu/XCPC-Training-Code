#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 函数前向声明
vector<int> build_bad_table(const string &pattern);
vector<int> build_good_table(const string &pattern);
bool isPrefix(const string &pattern, int p);
int suffixLength(const string &pattern, int p);

// 查找模式串在主串中的位置
int pattern(const string &pattern, const string &target) {
    int tLen = target.length(); // 主串长度
    int pLen = pattern.length(); // 模式串长度

    if (pLen > tLen) {
        return -1; // 如果模式串比主串长，返回 -1
    }

    vector<int> bad_table = build_bad_table(pattern); // 创建坏字符表
    vector<int> good_table = build_good_table(pattern); // 创建好后缀表

    for (int i = pLen - 1, j; i < tLen;) {
        for (j = pLen - 1; target[i] == pattern[j]; i--, j--) {
            if (j == 0) {
                return i; // 匹配成功，返回匹配位置
            }
        }
        i += max(good_table[pLen - j - 1], bad_table[target[i]]); // 跳过坏字符
    }
    return -1; // 未找到匹配
}

// 构建坏字符表
vector<int> build_bad_table(const string &pattern) {
    const int table_size = 256; // 字符种类
    vector<int> bad_table(table_size, pattern.length()); // 初始化为模式串长度

    for (int i = 0; i < pattern.length() - 1; i++) {
        bad_table[pattern[i]] = pattern.length() - 1 - i; // 更新坏字符表
    }
    return bad_table;
}

// 构建好后缀表
vector<int> build_good_table(const string &pattern) {
    int pLen = pattern.length();
    vector<int> good_table(pLen, pLen); // 初始化为模式串长度
    int lastPrefixPosition = pLen;

    for (int i = pLen - 1; i >= 0; --i) {
        if (isPrefix(pattern, i + 1)) {
            lastPrefixPosition = i + 1; // 更新前缀位置
        }
        good_table[pLen - 1 - i] = lastPrefixPosition - i + pLen - 1; // 更新好后缀表
    }

    for (int i = 0; i < pLen - 1; ++i) {
        int slen = suffixLength(pattern, i); // 计算后缀长度
        good_table[slen] = pLen - 1 - i + slen; // 更新好后缀表
    }
    return good_table;
}

// 检查前缀匹配
bool isPrefix(const string &pattern, int p) {
    int patternLength = pattern.length();
    for (int i = p, j = 0; i < patternLength; ++i, ++j) {
        if (pattern[i] != pattern[j]) {
            return false; // 不匹配
        }
    }
    return true; // 匹配
}

// 计算后缀长度
int suffixLength(const string &pattern, int p) {
    int pLen = pattern.length();
    int len = 0;
    for (int i = p, j = pLen - 1; i >= 0 && pattern[i] == pattern[j]; i--, j--) {
        len++; // 增加匹配长度
    }
    return len;
}

// 主函数测试
int main() {
    string target = "ababcabcacbab"; // breakpoint
    string patternStr = "abc";

    int index = pattern(patternStr, target);
    if (index != -1) {
        cout << "Pattern found at index: " << index << endl;
    } else {
        cout << "Pattern not found." << endl;
    }

    return 0;
}
