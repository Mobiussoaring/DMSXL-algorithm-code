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

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> A; // 哈希表储存链表A的结点
        ListNode* tem=headA;
        while (tem)
        {
            A.insert(tem);
            tem=tem->next;
        }

        tem=headB;
        while (tem) // 遍历链表B，找到重复的第一个就停止
        {
            if(A.find(tem)!=A.end()) return tem;
            tem=tem->next;
        }
        return tem;
    }
};