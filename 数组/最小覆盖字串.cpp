#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> sN;                 // 串s的哈希表，储存窗口内元素及其个数
        unordered_map<char, int> tN;                 // 串t的哈希表，储存窗口内元素及个数
        string result = "";                          // 结果
        int left = 0, sublen = INT32_MAX, ansL = -1; // 左指针、最短子串长度、答案的左指针

        for (char tem : t) // 初始化t的哈希表
        {
            tN[tem]++;
        }

        for (int right = 0; right < s.size(); right++) // 开始套模板
        {
            if (tN.find(s[right]) != tN.end())
            {
                sN[s[right]]++;
            }

            while (isCover(sN, tN)) // 当能覆盖t时缩小窗口
            {
                if (sublen >= right - left + 1) // 记录此时的结果串和长度
                {
                    sublen = right - left + 1;
                    ansL = left; // 此时子串的开始
                }
                sN[s[left]]--;
                left++; // 左指针右移
            }
        }
        return ansL == -1 ? result : s.substr(ansL, sublen);
    }

    bool isCover(unordered_map<char, int> &s, unordered_map<char, int> &t) // 判断s是否覆盖t
    {
        for (const auto &it : t)
        {
            if (s[it.first] < it.second)
            {
                return false;
            }
        }
        return true;
    }
};