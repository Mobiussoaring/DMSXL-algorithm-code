#include <iostream>
#include<unordered_set>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 使用哈希表
class Solution1 {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode* cur=head;
        while (cur)
        {
            if(visited.find(cur)!=visited.end()) return cur;
            visited.insert(cur);
            cur=cur->next;
        }
        return cur;
    }
};

// 使用双指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*fast=head; // 快指针，速度是慢指针的两倍
        ListNode* slow=head;
        while (fast)
        {
            if(!fast->next) return nullptr; // 保证下面fast->next不为空
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                ListNode* ptr=head; // 相等的时候，初始化一个在head的指针
                while (ptr!=slow) // ptr和slow一个走的速度，最后会在环入口相遇
                {
                    ptr=ptr->next;
                    slow=slow->next;
                }
                return ptr;
            }
        }
        return fast;
    }
};