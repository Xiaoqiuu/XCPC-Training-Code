#include <iostream>
using namespace std;

typedef struct ListNode
{
	int *elem; /* 存储空间基址 */
	int length; /* 当前长度 */
	int listsize; /* 当前分配的存储容量(以sizeof(ElemType)为单位) */
} ListNode;

void InitList(ListNode& L) {
    L.next = NULL;
}


signed main() {
    
}