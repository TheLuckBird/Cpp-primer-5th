#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

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

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // ListNode *p = headA;
    // while (p)
    // {
    //     ListNode *q = headB;
    //     while (q)
    //     {
    //         if(p==q) return p;
    //         q = q->next;
    //     }
    //     p = p->next;
        
    // }
    // return NULL;

    ListNode *p = headA;
    ListNode *q = headB;
    while (p!=q)
    {
        p = p == NULL ? headB : p->next;
        q = q == NULL ? headA : q->next;
    }//太精妙了
    return p;
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

    ListNode l1(4);
    ListNode l2(1);l1.next=&l2;
    ListNode l3(8);l2.next=&l3;
    ListNode l4(4);l3.next=&l4;
    ListNode l5(5);l4.next=&l5;

    ListNode a1(5);
    ListNode a2(6);a1.next=&a2;
    ListNode a3(1);a2.next=&a3;
    a3.next=&l3;

    auto v = getIntersectionNode(&l1,&a1);
    
    cout << (v == NULL ? "NULL" : to_string((v->val))) << endl;


    return 0;
}
