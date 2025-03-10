#include <iostream>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(-1), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode *n) : val(v), next(n) {}
};

class MyLinkedList
{
private:
    ListNode *head; // 头指针是虚拟头节点
    int size; // 链表大小从虚拟头节点之后记

public:
    MyLinkedList()
    {
        this->size = 0;
        this->head = new ListNode(-1);
    }

    ~MyLinkedList()
    {
        while (head != nullptr)
        {
            ListNode *tem = head;
            head = head->next;
            delete tem;
        }
    }

    int get(int index)
    {
        if (index >= 0 && index < size)
        {
            ListNode *cur = head;
            for (int i = 0; i <= index; i++)
            {
                cur = cur->next;
            }
            return cur->val;
        }
        return -1;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index >= 0 && index <= size)
        {
            ListNode *cur = head;
            for (int i = 0; i < index; i++) // 注意我们要得到index的前一个结点
            {
                cur = cur->next;
            }
            ListNode *newnode = new ListNode(val);
            newnode->next = cur->next;
            cur->next = newnode;
            size++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index >= 0 && index < size)
        {
            ListNode *cur = head;
            for (int i = 0; i < index; i++) // 注意要得到index的前一个结点
            {
                cur = cur->next;
            }
            ListNode *tem = cur->next;
            cur->next = cur->next->next;
            delete tem;
            size--;
        }
    }
};