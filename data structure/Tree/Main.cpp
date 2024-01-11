#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "node.h"
#include "BinarySearchTree.h"

using namespace std;

//层序遍历，迭代实现
vector<BinaryNode<int> *> level_order_traversal(BinaryNode<int> *root)
{
    vector<BinaryNode<int> *> level;
    BinaryNode<int> *p = root;
    queue<BinaryNode<int> *> Queue;

    Queue.push(p);
    while(!Queue.empty())
    {
        BinaryNode<int> *temp = Queue.front();
        Queue.pop();
        if(temp->left) Queue.push(temp->left);
        if(temp->right) Queue.push(temp->right);
        level.push_back(temp);
    }

    return level;

}

//层序遍历，递归实现
int height(BinaryNode<int>* root) {
    if (root == nullptr) return 0;
    return 1 + std::max(height(root->left), height(root->right));
}

void printGivenLevel(BinaryNode<int>* root, int level) {
    if (root == nullptr) return;
    if (level == 1) std::cout << root->element << " ";
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void levelOrderTraversal(BinaryNode<int>* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) printGivenLevel(root, i);
}

//前序遍历，迭代实现
vector<int> preordertraversaliter(BinaryNode<int> *root)
{
    vector<int> vec;
    vec.push_back(root->element);
    stack<BinaryNode<int> *> Stack;
    BinaryNode<int> *p = root;

    Stack.push(root);
    while(!Stack.empty())
    {
        if(p)
        {
            p = p->left;
            if(p != nullptr)
            {
                Stack.push(p);
                vec.push_back(p->element);
            }
        }
        else
        {
            p = Stack.top()->right;
            Stack.pop();
            if(p != nullptr)
            {
                Stack.push(p);
                vec.push_back(p->element);
            }
        }  
    }

    return vec;
}

//前序遍历，递归实现
void preorder(BinaryNode<int> *root,vector<int> &vec)
{
    if(root == nullptr) return;
    vec.push_back(root->element);
    preorder(root->left,vec);
    preorder(root->right,vec);
}

vector<int> preordertraversal(BinaryNode<int> *root)
{
    vector<int> vec;
    preorder(root,vec);
    return vec;
}

//中序遍历，迭代实现
vector<int> inordertraversaliter(BinaryNode<int> *root)
{
    vector<int> vec;
    stack<BinaryNode<int> *> Stack;
    Stack.push(root);
    BinaryNode<int> *p = root;

    while(!Stack.empty())
    {
        if(p)
        {
            p = p->left;
            if(p != nullptr)
                Stack.push(p);
        }
        else
        {
            vec.push_back(Stack.top()->element);
            p = Stack.top()->right;
            Stack.pop();
            if(p != nullptr)
                Stack.push(p);
        }
    }
    return vec;

}

//后序遍历，迭代实现(反转法)
vector<int> postordertraversaliter(BinaryNode<int> *root)
{
    stack<BinaryNode<int> *> Stack;
    vector<int> vec;
    if(root ==nullptr) return vec;
    BinaryNode<int> *p = root;

    while(!Stack.empty() || p)
    {
        while(p != nullptr)
        {
            vec.push_back(p->element);
            Stack.push(p);
            p = p->right;
        }

        p = Stack.top();
        Stack.pop();
        p = p->left;

    }
    reverse(vec.begin(),vec.end());
    return vec;

}

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

    // vector<int> ivec {1,3,5,4};
    // BinarySearchTree<int> tree;
    // for(auto p:ivec) 
    //     tree.insert(p);
    // tree.printTree();

    // tree.remove(3);

    // cout << "--" << endl;

    // tree.printTree();

    BinaryNode<int> *b9 = new BinaryNode<int>(9);
    BinaryNode<int> *b8 = new BinaryNode<int>(8);
    BinaryNode<int> *b6 = new BinaryNode<int>(6);
    BinaryNode<int> *b7 = new BinaryNode<int>(7,nullptr,b9);
    BinaryNode<int> *b1 = new BinaryNode<int>(5,b8,b7);
    BinaryNode<int> *b2 = new BinaryNode<int>(4,nullptr,b1);
    BinaryNode<int> *b3 = new BinaryNode<int>(3,nullptr,b6);
    BinaryNode<int> *b4 = new BinaryNode<int>(2,b2,nullptr);
    BinaryNode<int> *b5 = new BinaryNode<int>(1,b4,b3);
    

    auto level = level_order_traversal(b5);
    for(auto p:level)
    {
        cout << p->element << " ";
    }
    cout << endl;

    levelOrderTraversal(b5);

    cout << endl;

    cout << "前序遍历，递归实现" << endl;
    auto vec = preordertraversal(b5);
    for(auto p:vec)
    {
        cout << p << " ";
    }
    cout <<endl;

    cout << "前序遍历，迭代实现" << endl;
    for(auto p:preordertraversaliter(b5))
    {
        cout << p << " "; 
    }
    cout << endl;

    cout << "中序遍历，迭代实现"  << endl;
    for(auto p:inordertraversaliter(b5))
        cout << p << " ";
    cout << endl;

    cout << "后序遍历，迭代实现" << endl;
    for(auto p:postordertraversaliter(b5))
        cout << p <<" ";
    cout << endl;

    cout << "20240110" << endl;

    return 0;
}
