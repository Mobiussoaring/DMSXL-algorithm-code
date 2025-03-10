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

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(-1, head); // 虚拟头节点
        ListNode *cur = dummyHead;
        while (cur->next != nullptr) // 注意是cur->next，因为要进行next赋值
        {
            if (cur->next->val == val)
            {
                ListNode *tem = cur->next;
                cur->next = cur->next->next;
                delete tem; // 后面不要加cur = cur->next
            }
            else
            {
                cur = cur->next;
            }
        }
        head = dummyHead->next; // 注意是dummy->next
        delete dummyHead;
        return head;
    }
};