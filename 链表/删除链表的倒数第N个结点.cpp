#include<iostream>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummyHead = new ListNode(-1,head);
        ListNode* left=dummyHead; // 长度为n+1的尺子的左端点
        ListNode* right=dummyHead; // 长度为n+1的尺子的右端点
        while (n>0)
        {
            right=right->next; // 把尺子扩充到n+1
            n--;
        }
        
        while (right->next) // 移动尺子到链表末尾
        {
            left=left->next;
            right=right->next;
        }
        
        // 删除倒数第n个结点
        ListNode * tem = left->next;
        left->next=left->next->next;
        delete tem;

        return dummyHead->next;
        delete dummyHead;
    }
};