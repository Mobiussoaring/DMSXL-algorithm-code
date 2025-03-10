#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(-1), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode *n) : val(v), next(n) {}
};

// 递归解法
class Solution1
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head; // 当head为空或者head的后一个为空直接返回
        }

        ListNode *nextHead = swapPairs(head->next->next); // 返回的是已经处理好的链表头结点
        ListNode *newHead = head->next;                   // 交换之后头节点变成下一个结点，需要提前记录
        head->next->next = head;
        head->next = nextHead;
        return newHead;
    }
};

// 迭代解法
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *first = cur->next;
            ListNode *second = cur->next->next;
            cur->next = second; // 注意这里要把cur的next赋值为第二个结点，不然链表会断
            first->next = second->next;
            second->next = first;
            cur = first;
        }
        return dummyHead->next;
        delete dummyHead;
    }
};