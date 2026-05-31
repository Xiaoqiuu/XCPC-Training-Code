/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-05-28 19:34:29
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-05-28 19:37:54
 * @FilePath: /workspace/408/WD_DS/2/2.c
 * @Description: XCPC | 408 | Unity | Agents
 */
#include <stdio.h>
// #incldue <srtdio.h>
#define akitama return 0

typedef struct ThreadNode{
    char data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
}ThreadNode, *ThreadTree;

void InThread(ThreadTree T, ThreadTree* pre) {
    if (T != NULL) {
        InThread(T, pre);
        if (T->lchild == NULL) {
            T->lchild = *pre;
            T->ltag = 1;
        }
    }
}

signed main() {

}
//