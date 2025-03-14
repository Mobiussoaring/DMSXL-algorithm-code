#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false; // 先判断长度是否相同

        unordered_map<char, int> stringS; // 储存s中的字母和个数
        for (int i = 0; i < s.size(); i++)
        {
            stringS[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++)
        { // 遍历t中字母，减少个数
            stringS[t[i]]--;
            if (stringS[t[i]] < 0)
                return false;
        }
        return true;
    }
};