#include<bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> instack;
    stack<int> outstack;

public:
    MyQueue() {}

    void push(int x) { instack.push(x); }

    int pop() {
        if (outstack.empty()) {
            while (!instack.empty()) {
                int tem = instack.top();
                outstack.push(tem);
                instack.pop();
            }
        }
        int tem = outstack.top();
        outstack.pop();
        return tem;
    }

    int peek() {
        int tem = this->pop(); // 调用pop先得到顶部元素，然后再压回outstack
        outstack.push(tem);
        return tem;
    }

    bool empty() { return instack.empty() && outstack.empty(); }
};