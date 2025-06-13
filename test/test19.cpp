// 手搓stack

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

#define ll long long
#define MAX_N 100000
#define akitama return 0

#define rp(i, a, b) for(int i=(a); i<=(b); i++)

struct stack{
    int s[MAX_N], top = 0;
    void push(int x) { s[++top] = x }
    int top(int x) { return s[top]; }
    void pop() { top--; };
    bool empty() { return top == 0; }
};

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    rp(i, 1, 4) {
        cout << s.top(i) << " ";
    }
    cout << endl;
    delete s;
    akitama;
}