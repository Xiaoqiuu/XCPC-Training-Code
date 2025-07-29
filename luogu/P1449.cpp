#include <bits/stdc++.h>
using namespace std;

signed main() {
    stack<int> a;
    string s; cin >> s;
    string num = "";
    // int num1, num2;
    // ll ans = 0;
    for (int i = 0; i < (int)s.size(); ++ i) {
        // string num = ;
        if (s[i] >= '0' && s[i] <= '9') num += s[i];
        else if (s[i] == '.') {
            a.push(stoi(num));
            // cout << "the number is : " << a.top() << endl;
            num = "";
        } else if (s[i] == '+') {
            int num1 = a.top();
            a.pop();
            int num2 = a.top();
            a.pop();
            a.push(num1 + num2);
        } else if (s[i] == '-') {
            int num1 = a.top();
            a.pop();
            int num2 = a.top();
            a.pop();
            a.push(num2 - num1);
        } else if (s[i] == '*'){
            int num1 = a.top();
            a.pop();
            int num2 = a.top();
            a.pop();
            a.push(num1 * num2);
        } else if (s[i] == '/') {
            int num1 = a.top();
            a.pop();
            int num2 = a.top();
            a.pop();
            a.push(num2 / num1);
        }
    }
    cout << a.top() << endl;
}