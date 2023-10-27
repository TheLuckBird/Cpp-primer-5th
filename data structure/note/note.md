# **数据结构与算法分析 -C++语言描述 第四版**
## **Data Structures and Algorithm Analysis in C++ Fourth Edition **

## 第三章 表、栈和队列
表：数组、链表，STL中的vector、list

栈(stack):操作受限的表，插入删除只能在一端进行，即表的末端，称之为top。

基本操作：pop(出栈)、push(入栈)

实现：数组实现、链表实现

应用:后缀表达式、中缀表达式转后缀表达式

队列(queue):入队(enqueue)在队尾(back)，出队(dequeue)在对头(front)

实现：数组实现、链表实现

应用:打印机、文件服务器、购票

## 第四章 树
一棵树是n个节点和n-1条边的集合。定义树的一种自然方式是递归。

没有儿子的节点是树叶，父亲相同的节点是兄弟(siblings)。

应用:操作系统的目录结构

实现树的一种方法是在每一个节点除数据外还要有一些链，使得该节点的每一个儿子都被一个链所链接。然而，由于每个节点的儿子数可以变化很大并且事先不知道，因此在数据
结构中建立到各(儿)子节点直接的链接是不可行的，因为这样会产生太多浪费的空间。实际
上解决方法很简单:将每个节点的所有儿子都放在树节点的链表中。

```
struct TreeNode
{
    int data;
    TreeNode *firstChild;
    TreeNode *nextSibling;
};
```

通常被称为 "孩子-兄弟表示法" 或 "左子右兄表示法"。这种表示方法在树或森林结构中很有用，其中每个节点可以有多个孩子，并且兄弟节点之间通过链表相连。

这种表示方法的一个优点是它更节省空间。它只需要存储每个节点的数据以及两个指针，而不需要为每个可能的孩子分配额外的空间。当树的分支因子不确定或非常大时，这种表示方法非常实用。

二叉树

树的节点最多有两个儿子。
```
template<typename T> 
class BinaryNode
{
    T element;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode(T data):element(data),left(nullptr),right(nullptr){}
};
```

应用(与搜索无关的):表达式树(编译器设计)

二叉搜索树:一棵左孩子节点值小于父亲节点值小于右孩子节点值的二叉树

insert:
```
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, BinaryNode * & t )
    {
        if( t == nullptr )
            t = new BinaryNode{ x, nullptr, nullptr };
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else
            ;  // Duplicate; do nothing
    }
```
在递归例程中，唯一次t变化的时刻是在一片新树叶创建的时候。此时意味着，递归例程已经从某个其他的节点p处被调用，而这个节点将是新建树叶的父亲。该调用将是insert(x,p->left)或insert (x,p->right)。不管哪种方法，t现在都是对p->left 或p->right的引用，这就意味着p->left或p->right将改变以指向新的节点。

remove:
```
    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( const Comparable & x, BinaryNode * & t )
    {
        if( t == nullptr )
            return;   // Item not found; do nothing
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        /经过上面两个if,走到下面的都是节点值与x相等的，分为两种情况
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else//一个孩子或没有孩子
        {
            BinaryNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }
    }
```

insert第二个参数是引用类型,`t = root->left;`，就是子树根节点右孩子指向t,`t = ( t->left != nullptr ) ? t->left : t->right;`,`root->right = t->right;`,就是子树根节点右孩子指向t的右孩子
