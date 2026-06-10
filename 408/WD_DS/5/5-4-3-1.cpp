/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-06-03 15:43:54
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-06-03 15:56:49
 * @FilePath: /workspace/408/WD_DS/5/5-4-3-1.cpp
 * @Description: XCPC | 408 | Unity | Agents
 */
#include <cstdio>
#include <queue>
#define akitama return 0

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} TreeNode, *Tree;

std::queue<Tree> q;

void LevelOrder(TreeNode* root) {
    if (root != NULL) {
        q.push(root);
    }
    while (!q.empty()) {
        if (q.front()->left != NULL) q.push(q.front()->left);
        if (q.front()->right != NULL) q.push(q.front()->right);
        q.pop();
    }
}

void LevelOrder2(TreeNode* root) {
    if (root == NULL)
        return;

    TreeNode*  queue[100];   // 用数组模拟队列
    int front = 0;
    int rear = 0;

    queue[rear++] = root;   // 根结点入队

    while (front != rear) {
        TreeNode*  p = queue[front++];   // 队头出队

        // 访问结点的位置
        printf("%c ", p->data);

        if (p->left != NULL)
            queue[rear++] = p->left;

        if (p->right != NULL)
            queue[rear++] = p->right;
    }
}

signed main () {

}