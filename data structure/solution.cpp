#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;



// vector<int> twoSum(vector<int>& nums, int target)
// {
//     vector<int> output(2);
//     for(int i=0;i!=nums.size();++i)
//         for(int j=i+1;j!=nums.size();++j)
//             if(nums[i]+nums[j]==target)
//                 output[0] = i,output[1] = j;
//     return output;
// }

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int,int> hash;
    for(int i=0;i!=nums.size();++i)
    {
        if(hash.find(target-nums[i])!=hash.end()) return {hash.at(target-nums[i]),i};
        else hash[nums[i]] = i;
    }
    return {};
}

void moveZeroes(vector<int>& nums)
{
    int count = 0;
    for(int i = 0 ; i!=nums.size();++i)
    {
        if(nums[i] == 0) ++count;
        else nums[i-count] = nums[i];
    } 

    while(count)
    {
        nums[nums.size()-count] = 0;
        --count;
    }
}

// struct ListNode 
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
// {
//     // ListNode *p = headA;
//     // while (p)
//     // {
//     //     ListNode *q = headB;
//     //     while (q)
//     //     {
//     //         if(p==q) return p;
//     //         q = q->next;
//     //     }
//     //     p = p->next;
        
//     // }
//     // return NULL;

//     ListNode *p = headA;
//     ListNode *q = headB;
//     while (p!=q)
//     {
//         p = p == NULL ? headB : p->next;
//         q = q == NULL ? headA : q->next;
//     }//太精妙了
//     return p;
// }

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_list(ListNode *p)
{
    while(p)
    {
        cout << p->val <<" ";
        p = p->next;
    }
    cout << endl;
}

ListNode* reverseList(ListNode* head) {
    if(head==nullptr) return nullptr;
    ListNode *p = head;
    ListNode *q = head->next;
    if(q==nullptr) return p;
    ListNode *r = q->next;
    p->next = nullptr;

    if(r==nullptr)
    {
        q->next = p;
        return q;
    }
     
    while(r)
    {
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    return q;  
}

bool isPalindrome(ListNode* head)
{
    vector<int> ivec;
    if(head)
    {
        ListNode *curr = head;
        while (curr) 
        {
            ivec.push_back(curr->val);
            curr = curr->next;
        }

        for(auto i=ivec.begin(),j = ivec.end()-1;i!=j;++i,--j)
        {
            if(*i != *j) return false; 
        }
        return true;
    }
    else 
        return false;
    
}

// bool hasCycle(ListNode *head)
// {
//     ListNode *pre = head;
//     if(pre == nullptr) return false;
//     ListNode *curr = head->next;
//     if(curr == nullptr) return false;

//     while(pre)
//     {
//         while(curr)
//         {
//             if(curr->next == pre) return true;
//             curr = curr->next;
//         }
//         pre = pre->next;
//         curr = pre->next;
//     }
//     return false;
// }

bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true; // 如果它们相遇，说明链表中有环
        }
    }

    return false; // 如果循环结束，没有找到环
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode head;
    ListNode *curr = &head;
    ListNode *p = list1;
    ListNode *q = list2;

    while(p && q)
    {
        if(p->val < q->val)
        {
            curr->next = p;
            curr = p;
            p = p->next;
        } 
        else 
        {
            curr->next = q;
            curr = q;
            q = q->next;
        }
        // curr = curr->next;
    }

    if(p) curr->next = p;
    if(q) curr->next = q;

    return head.next;
}

// ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//     ListNode dummy(0); // 创建一个哨兵节点以简化代码
//     ListNode* curr = &dummy; // 用于遍历新链表

//     ListNode* p = list1;
//     ListNode* q = list2;

//     while (p && q) {
//         if (p->val < q->val) {
//             curr->next = p;
//             p = p->next;
//         } else {
//             curr->next = q;
//             q = q->next;
//         }
//         curr = curr->next;
//     }

//     if (p) {
//         curr->next = p;
//     } else {
//         curr->next = q;
//     }

//     return dummy.next;
// }

bool isValid(string s)
{
    stack<char> op;
    // if(s.size() % 2) return false;
    for(int i = 0; i != s.size();++i)
    {
        if(op.empty()) op.push(s[i]);
        else
        {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                op.push(s[i]);
            }
            else if(s[i] == '}' && op.top() == '{') op.pop();
            else if(s[i] == ']' && op.top() == '[') op.pop();
            else if(s[i] == ')' && op.top() == '(') op.pop();
            else return false;
        }
         
    }
    return op.empty();
}

int singleNumber(vector<int>& nums)
{
    set<int> Unique;
    for(auto p:nums)
    {
        if(Unique.find(p) == Unique.end()) 
            Unique.insert(p);
        else
            Unique.erase(p);
    }
    return *Unique.begin();
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

void inorder(TreeNode *root,vector<int> &ret)
{
    if(root == nullptr) return;
    inorder(root->left,ret);
    ret.push_back(root->val);
    inorder(root->right,ret);
}

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> ret;
    inorder(root,ret);
    return ret;
}

// TreeNode* invertTree(TreeNode* root)
// {
//     if(root == nullptr) return nullptr;
//     invertTree(root->left);
//     invertTree(root->right);
//     int temp = (root->left)->val;
//     (root->left)->val = (root->right)->val;;
//     (root->right)->val = temp;
//     return root;
// }

// bool isSymmetric(TreeNode* root)
// {
//     if(root == nullptr) return true;
//     bool l = isSymmetric(root->left);
//     bool r = isSymmetric(root->right);

//     if (root->left == nullptr && root->right == nullptr) {
//     return true; // 左右子树都为空，对称
//     }
    
//     if (root->left == nullptr || root->right == nullptr) {
//         return false; // 左右子树一个为空一个不为空，不对称
//     }

//     return ((root->left)->val == (root->right)->val) && l && r;
// }

bool isMirror(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) {
        return true; // 左右子树都为空，对称
    }
    
    if (left == nullptr || right == nullptr) {
        return false; // 左右子树一个为空一个不为空，不对称
    }
    
    return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
        return true; // 空树是对称的
    }
    
    return isMirror(root->left, root->right);
}

int main(int argc, char const *argv[])
{
    // vector<int> nums= {2,7,11,15};
    // int target = 17;
    // vector<int> output = twoSum(nums,target);
    // for_each(output.begin(),output.end(),[](int v){cout << v << " ";});
    // cout << endl;

    // std::unordered_map<std::string, int> myMap;

    // // 向 unordered_map 添加一些键值对
    // myMap["apple"] = 10;
    // myMap["banana"] = 5;
    // myMap["cherry"] = 15;

    // // 使用 at 查找键对应的值
    // std::string key = "banana";
    // try {
    //     int value = myMap.at(key);
    //     std::cout << "The value for key '" << key << "' is: " << value << std::endl;
    // } catch (const std::out_of_range& e) {
    //     std::cerr << "Key '" << key << "' not found in the map." << std::endl;
    // }

    // vector<int> nums = {0,1,0,3,12,9,0,8,9,0};
    // moveZeroes(nums);
    // for_each(nums.begin(),nums.end(),[](int v){cout << v << " ";});

    // ListNode l1(4);
    // ListNode l2(6);l1.next=&l2;
    // ListNode l3(8);l2.next=&l3;
    // ListNode l4(10);l3.next=&l4;
    // ListNode l5(40);

    // ListNode a1(5);
    // ListNode a2(60);a1.next=&a2;
    // ListNode a3(100);a2.next=&a3;
    // a3.next=&l3;

    // auto v = getIntersectionNode(&l1,&a1);
    
    // cout << (v == NULL ? "NULL" : to_string((v->val))) << endl;
    // ListNode *v = &l1;
    // while (v)
    // {
    //     cout << v->val << " ";
    //     v = v->next;
    // }
    // cout << endl;

    // auto p = reverseList(&l1);
    // while (p)
    // {
    //     cout << p->val << " ";
    //     p = p->next;
    // }
    // cout << endl;

    // cout << isPalindrome(&l1) << endl;

    // ListNode l6(10);l6.next = &l2;
    // cout << hasCycle(&l1) << endl;

    // ListNode *v = &l1;
    // while (v)
    // {
    //     cout << v->val << " ";
    //     v = v->next;
    // }
    // cout << endl;

    // print_list(&l1); 
    // print_list(&a1); 
    // auto iter = mergeTwoLists(&l1,&a1);
    // print_list(iter);

    // cout << (nullptr && nullptr) << endl;

    // cout << isValid("()") << endl; 
    // cout << isValid("(){}[]") << endl; 
    // cout << isValid("(})") << endl; 
    // cout << isValid("(]])") << endl; 

    // vector<int> ivec = {9};
    // cout << singleNumber(ivec) << endl;

    
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(2);
    TreeNode *p4 = new TreeNode(2);
    TreeNode *p5 = new TreeNode(1,p1,p2);
    TreeNode *p6 = new TreeNode(1,p3,p4);
    TreeNode *p7 = new TreeNode(9,p5,p6);

    // vector<int> ivec = inorderTraversal(p3);
    // for_each(ivec.begin(),ivec.end(),[](int val){cout << val << " ";});
    
    cout << isSymmetric(p7) << endl;
    return 0;
}
