#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) return "";
    
    // 预处理字符串，插入特殊字符
    string t = "^#";
    for (char c : s) {
        t += c;
        t += '#';
    }
    t += '$';
    
    int n = t.size();
    vector<int> p(n, 0);  // 回文半径数组
    int center = 0, right = 0;
    int max_len = 0, start = 0;
    
    for (int i = 1; i < n - 1; ++i) {
        // 利用对称性快速初始化p[i]
        if (i < right) {
            p[i] = min(right - i, p[2 * center - i]);
        }
        
        // 中心扩展
        while (t[i + p[i] + 1] == t[i - p[i] - 1]) {
            p[i]++;
        }
        
        // 更新最右边界和中心
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
        
        // 记录最长回文子串
        if (p[i] > max_len) {
            max_len = p[i];
            start = (i - p[i]) / 2;
        }
    }
    
    return s.substr(start, max_len);
}

int main() {
    string s;
    cin >> s;
    string result = longestPalindrome(s);
    cout << "Longest palindromic substring: " << result << endl;
    cout << "Length: " << result.length() << endl;
    return 0;
}