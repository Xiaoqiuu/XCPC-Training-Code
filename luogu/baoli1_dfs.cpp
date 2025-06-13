#include <iostream>
using namespace std;

const int MAX_R = 100;
const int MAX_C = 100;

int R, C, K;
char grid[MAX_R][MAX_C];
bool visited[MAX_R][MAX_C];
int dx[] = {1, -1, 0, 0}; // 行的变化
int dy[] = {0, 0, 1, -1}; // 列的变化

void dfs(int x, int y, int &count) {
    visited[x][y] = true; // 标记为已访问
    count++; // 统计连通空格的数量

    // 遍历四个方向
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 检查边界和是否为未访问的空格
        if (nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] != '#' && !visited[nx][ny]) {
            dfs(nx, ny, count);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans = 0;

    cin >> R >> C >> K; // R 行数, C 列数, K 目标连通空格数量
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j]; // 读取网格
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] != '#' && !visited[i][j]) { // 如果是空格并且未被访问
                int count = 0;
                dfs(i, j, count);
                if (count >= K) {
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
