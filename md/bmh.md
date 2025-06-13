----------------
[TOC]

# 1. KMP

# 2. BMH

BMH是BM算法的一种优化，旨在减少匹配失败的次数。

## 算法实例

```cpp{.line-numbers}
#include <iostream>  
#include <vector>  
#include <string>  
#include <unordered_map>  
  
// 预处理模式串，生成坏字符表  
void preprocessPattern(const std::string& pattern, std::unordered_map<char, int>& badCharTable) {  
    int m = pattern.size();  
    for (int i = 0; i < m; ++i) {  
        badCharTable[pattern[i]] = m - 1 - i;  
    }  
}  
  
// BMH算法主函数  
std::vector<int> boyerMooreHorspool(const std::string& text, const std::string& pattern) {  
    std::vector<int> result;  
    int n = text.size();  
    int m = pattern.size();  
      
    if (m == 0 || n == 0 || m > n) {  
        return result; // 特殊情况处理  
    }  
      
    std::unordered_map<char, int> badCharTable;  
    preprocessPattern(pattern, badCharTable);  
      
    int s = 0; // s是文本T中开始匹配的位置  
    while (s <= n - m) {  
        int j = m - 1;  
          
        // 从右向左扫描模式串和文本  
        while (j >= 0 && pattern[j] == text[s + j]) {  
            --j;  
        }  
          
        if (j < 0) {  
            // 完全匹配  
            result.push_back(s);  
            s += badCharTable.count(text[s + m - 1]) ? badCharTable[text[s + m - 1]] : m;  
        } else {  
            // 根据坏字符规则跳过字符  
            s += std::max(1, j - badCharTable[text[s + j]]);  
        }  
    }  
      
    return result;  
}  
  
int main() {  
    std::string text = "HERE IS A SIMPLE EXAMPLE";  
    std::string pattern = "EXAMPLE";  
      
    std::vector<int> matches = boyerMooreHorspool(text, pattern);  
      
    std::cout << "Pattern found at positions: ";  
    for (int pos : matches) {  
        std::cout << pos << " ";  
    }  
    std::cout << std::endl;  
      
    return 0;  
}
```

# 3. AC自动机