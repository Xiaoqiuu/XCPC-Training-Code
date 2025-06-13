#include <iostream>
#include <cstring>
using namespace std;
#define akitama return 0

class Solution {
public:
    int longestValidParentheses(string s) {
        const char *ch = s.c_str();
        int count = 0, ans = 0, l_n = 0, r_n = 0;
        bool l = false, r = false;
        for(int i = 0;i < strlen(ch);i ++){
            if(ch[i]=='(')l = true, l_n++;
            else if(ch[i]==')')r = true, r_n++;
            if(l&&r)count++, l = false, r = false,l_n = 0, r_n = 0;
            if(l_n >= 2 || r_n >= 2)ans=max(ans,count), count = 0;
            ans=max(ans,count);
        }
        return ans;
    }
    
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution s;
    cout << s.longestValidParentheses("(()()))((((()))))))()()()()")<< endl;
    akitama;
}