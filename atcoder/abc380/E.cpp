#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class UnionFind {
private:
    vector<int> parent, size, color;
    unordered_map<int, int> colorCount;

public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        color.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            color[i] = i + 1;  // 初始颜色是唯一的，从1到N
            colorCount[color[i]]++;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // 路径压缩
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            // 联合按大小
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];

            // 更新颜色计数
            colorCount[color[rootX]] += colorCount[color[rootY]];
            colorCount.erase(color[rootY]);
        }
    }

    void setColor(int x, int newColor) {
        int root = find(x);
        int oldColor = color[root];
        if (oldColor != newColor) {
            colorCount[oldColor] -= size[root];
            if (colorCount[oldColor] <= 0) {
                colorCount.erase(oldColor);
            }
            color[root] = newColor;
            colorCount[newColor] += size[root];
        }
    }

    int countColor(int colorQuery) {
        return colorCount.count(colorQuery) ? colorCount[colorQuery] : 0;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, c;
            cin >> x >> c;
            --x;  // 转换为0索引
            uf.setColor(x, c);
            // 合并相邻格子，如果它们的颜色相同
            if (x > 0 && uf.find(x - 1) == uf.find(x)) {
                uf.merge(x - 1, x);
            }
            if (x < N - 1 && uf.find(x + 1) == uf.find(x)) {
                uf.merge(x, x + 1);
            }
        } else if (type == 2) {
            int c;
            cin >> c;
            cout << uf.countColor(c) << endl;
        }
    }

    return 0;
}
