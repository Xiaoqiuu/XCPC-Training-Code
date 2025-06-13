#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> generateSpiralMatrix(int m, int n) {
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    int num = 1;
    
    while (top <= bottom && left <= right) {
        
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = num++;
        }
        top++;
        
        
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = num++;
        }
        right--;
        
        if (top <= bottom) {
            
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }
        
        if (left <= right) {
            
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
    
    return matrix;
}

int main() {
    int m, n;
    cout << "请输入矩阵的行数和列数（用空格分隔）：";
    cin >> m >> n;
    
    vector<vector<int>> matrix = generateSpiralMatrix(m, n);
    
    // 输出矩阵
    for (const auto &row : matrix) {
        for (int num : row) {
            cout << setw(4) << num; // 设置宽度为4，保持对齐
        }
        cout << endl;
    }
    
    return 0;
}