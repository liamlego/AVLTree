#include <iostream>
#include "AVLTree.h"

using namespace std;




int main() {

    AVLTree tree;

    cout << "hello" << endl;

    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);

    tree.printTree(tree.root, "");
    return 0;
}