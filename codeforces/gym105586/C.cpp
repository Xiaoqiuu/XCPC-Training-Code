#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    // 用 lane[i] 表示第 i 号车道（1 <= i <= n）的空位区间 [l_i, r_i]
    vector<pair<long long, long long>> lane(n+1);
    for (int i = 1; i <= n; i++){
        long long l, r;
        cin >> l >> r;
        lane[i] = {l, r};
    }
    
    // dp[0] 表示车道 0 的时刻，由于车道 0 是人行道，无限制，我们令 dp[0] = 0
    long long prevTime = 0;  // 车道 0 上的时间
    
    long long curTime;
    // 处理第 1 号车道，由于车道 0无约束，可任意等待：
    curTime = max(prevTime + 1, lane[1].first);
    if(curTime > lane[1].second){
        cout << -1;
        return 0;
    }
    prevTime = curTime;
    
    // 处理车道 2 到 n
    for (int i = 2; i <= n; i++){
        // 最早出发时刻为 prevTime+1
        long long candidate = prevTime + 1;
        // 如果 candidate 小于 l_i，说明需要等待：
        if(candidate < lane[i].first){
            // 等待到时间 l_i-1 后再前进，此时到达车道 i 的时刻为 l_i，
            // 但必须保证在车道 i-1 等待到 l_i-1 是合法的，即 l_i-1 不超过车道 i-1 的 r 值
            if(lane[i-1].second < lane[i].first - 1){
                cout << -1;
                return 0;
            }
            candidate = lane[i].first;
        }
        // 如果 candidate 超过了车道 i 的允许时间，则无法通过
        if(candidate > lane[i].second){
            cout << -1;
            return 0;
        }
        prevTime = candidate;
    }
    
    // 最后从车道 n 前进一步到车道 n+1，n+1 是人行道，不受限制
    long long ans = prevTime + 1;
    cout << ans;
    
    return 0;
}
