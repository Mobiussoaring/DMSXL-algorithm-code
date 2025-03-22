#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int n = s.size();
        for (int i = 0; i < n; i = i + 2 * k) // 反转每个以2k下标开始的长为k的字符串
        {
            reverse(s.begin() + i, s.begin() + min(i + k, n)); // reverse函数左闭右开
        }
        return s;
    }
};