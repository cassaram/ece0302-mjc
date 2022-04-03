#include <iostream>
using std::cout;
using std::endl;

#include "BinaryTree.h"

typedef std::string ItemType;
typedef void (*FunctionType)(ItemType& anItem);

void PrintNode(ItemType& i) { cout << i << endl; };

int main(int argc, char** argv)
{
    BinaryTree<ItemType, FunctionType> T1("A");
    BinaryTree<ItemType, FunctionType> T2("B");
    BinaryTree<ItemType, FunctionType> T3("C");
    BinaryTree<ItemType, FunctionType> T4("D");
    BinaryTree<ItemType, FunctionType> T5("E");
    BinaryTree<ItemType, FunctionType> T6("F");

    // Create tree
    T2.attachLeftSubtree(T3);
    T2.attachRightSubtree(T4);

    T5.attachRightSubtree(T6);

    T1.attachLeftSubtree(T2);
    T1.attachRightSubtree(T5);

    // Test conditions
    T3.postorderTraverse(&PrintNode);   // Should be C,D,B,F,E,A
    T3.preorderTraverse(&PrintNode);    // Should be A,B,C,D,E,F
    T3.inorderTraverse(&PrintNode);     // Should be C,B,D,A,E,F

    // T1 should be only non-empty object

    return 0;
};
