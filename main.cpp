#include <iostream>
#include "BSTree.h"

using  namespace std;

int main() {

    BSTree<int> bsTree{8,6,9,5,7,3};

    cout << bsTree.size();
    bsTree.preOrder();

    bsTree.remove(5);
    cout << bsTree.size();
    bsTree.preOrder();
    return 0;
}