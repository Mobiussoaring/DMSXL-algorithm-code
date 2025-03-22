#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) // 长度不是2的倍数，一定不匹配
            return false;

        unordered_map<char, char> pairs = {{'(', ')'}, {'[', ']'}, {'{', '}'}}; // 储存对应的匹配对象
        stack<char> tem;

        for (const auto& character : s) {
            auto it = pairs.find(character); // 先看读入的字符是不是左边的
            if (it != pairs.end()) {
                tem.push(it->second); // 是的话直接把右边的入栈
            } else {
                if (tem.empty() || character != tem.top()) // 不是的话与栈顶元素比较
                    return false;
                tem.pop();
            }
        }
        return tem.empty();
    }
};