#include <iostream>
#include <vector>
#include "node.h"
#include "BinarySearchTree.h"

using namespace std;
int main(int argc, char const *argv[])
{
    // // 创建树节点
    // TreeNode* root = new TreeNode(1);
    // TreeNode* child1 = new TreeNode(2);
    // TreeNode* child2 = new TreeNode(3);
    // TreeNode* child3 = new TreeNode(4);

    // // 建立节点之间的关系
    // root->firstChild = child1;
    // child1->nextSibling = child2;
    // child2->nextSibling = child3;

    // // 遍历并打印树
    // printTree(root);

    // // 清理内存
    // delete root;
    // delete child1;
    // delete child2;
    // delete child3;

    vector<int> ivec {1,3,5,4};
    BinarySearchTree<int> tree;
    for(auto p:ivec) 
        tree.insert(p);
    tree.printTree();

    tree.remove(3);

    cout << "--" << endl;

    tree.printTree();

    return 0;
}
