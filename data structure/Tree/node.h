#pragma once
#include <iostream>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *firstChild;
    TreeNode *nextSibling;

    TreeNode(int val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}

};

void printTree(TreeNode* root) {
    if (root) {
        std::cout << root->data << " ";
        printTree(root->firstChild);   // 递归打印孩子节点
        printTree(root->nextSibling);  // 递归打印兄弟节点
    }
}

template<typename T> 
class BinaryNode
{
    T element;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode(T data):element(data),left(nullptr),right(nullptr){}
};

