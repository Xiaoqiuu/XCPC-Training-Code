#pragma G++ optimize(2)
#pragma G++ optimize(3)

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long int
#define akitama return 0

struct Node {
    int data;
    Node* next;
};


signed main() {
    int a[] = {7, 3, 2, 9, 8, 10, 13, 6, 1};
    //cout << nth_element(a, a + 5, a+ 9) << endl;

    printf("file : %s\n", __FILE__);
    printf("date : %s\n", __DATE__);
    printf("time : %s\n", __TIME__);
    printf("stdc : %s\n", __STDC__==1? "ANSI" : "UNKNOWN");

    printf("pointer testing...");
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    n3->next = n2;
    n2->next = n1;

    delete n1;
    delete n2;
    delete n3;
    akitama;
}