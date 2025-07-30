#include <bits/stdc++.h>
using namespace std;

signed main() {
    deque<int> dq;
    dq.push_front(1);
    dq.push_front(2);
    // 输出 2 1
    cout << dq.front() << " " << dq.back() << endl;
    dq.push_back(3);
    dq.pop_front();
    // 输出 1 3
    cout << dq.front() << " " << dq.back() << endl;
}