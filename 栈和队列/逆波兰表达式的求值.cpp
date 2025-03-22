#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tem;
        for(const auto& st : tokens){
            if(st=="+"||st=="-"||st=="*"||st=="/"){
                int right = tem.top();
                tem.pop();
                int left = tem.top();
                tem.pop();
                if(st=="+") tem.push(left+right);
                if(st=="-") tem.push(left-right);
                if(st=="*") tem.push(left*right);
                if(st=="/") tem.push(left/right);
            }
            else{
                tem.push(stoi(st)); // 转换为数值
            }
        }
        return tem.top();
    }
};