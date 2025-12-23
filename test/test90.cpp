#include <cstddef>
#include <iostream>

struct Tree {
    int val = 0;
    Tree *left;
    Tree *right;
    Tree (int x) : val(x), left(nullptr), right(nullptr) {}
};

signed main() {
    Tree* t1 = new Tree(1);
    Tree* t2 = new Tree(2);
    t.val = 0;
    t.left = t2;
    return 0;
}