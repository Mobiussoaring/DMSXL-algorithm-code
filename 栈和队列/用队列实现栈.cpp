#include<bits/stdc++.h>
using namespace std;

class MyStack {
    private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n = q.size();
        for(int i=0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
        int tem = q.front();
        q.pop();
        return tem;
    }
    
    int top() {
        int tem = this->pop();
        q.push(tem);
        return tem;
    }
    
    bool empty() {
        return q.empty();
    }
};