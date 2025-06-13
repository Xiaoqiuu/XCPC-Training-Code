#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long 
#define akitama return 0
#define vi vector<int>

const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
vi edge[N];
int cnt = 0;// 栈内有多少个元素

int dfs(int x) {
    if(edge[x].size() == 1) { // 达到终点
        for (int i = 1; i<= cnt; ++ i) {
            cout << a[i] << " "; // 输出解
        }
        return;
    }
    for (int i = 1; i <= egde[i].size(); ++ i) {
        if (edge[x][i]) {
            a[++cnt] = edge[x][i];// 保存结果
            dfs(x + 1);
            // 回溯一步
        }
    }
}

void solve() {

}

signed main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    solve();
    akitama;
}