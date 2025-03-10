#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 递归法
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // 这里必须把!head写在前面，因为链表为空的时候先判断head为空就不会进行后面的
        // 不然head为空，head->next会报错
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *newHead = reverseList(head->next); // 翻转之后链表的头节点
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

// 迭代法
class Solution2{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode * pre=nullptr; // 指向前一个指针
        ListNode * cur=head; // 指向当前指针
        while (cur!=nullptr)
        {
            ListNode *tem = cur->next;
            cur->next=pre;
            pre=cur;
            cur=tem;
        }
        return pre; // 最后是pre在头节点位置
    }
};