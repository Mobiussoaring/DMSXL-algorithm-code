#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int sIndex = s.size() - 1, tIndex = t.size() - 1; // 从右向左
        int skipS = 0, skipT = 0;                         // 记录此时有有多少个退格
        while (sIndex >= 0 || tIndex >= 0)                // 考虑最后可能index一正一负，所以取或
        {
            while (sIndex >= 0) // 找到s没被退格的下一个字母
            {
                if (s[sIndex] == '#')
                {
                    skipS++;
                    sIndex--;
                }
                else if (skipS > 0)
                {
                    sIndex--;
                    skipS--;
                }
                else
                {
                    break;
                }
            }

            while (tIndex >= 0) // 找到t没被退格的下一个字母
            {
                if (t[tIndex] == '#')
                {
                    tIndex--;
                    skipT++;
                }
                else if (skipT > 0)
                {
                    tIndex--;
                    skipT--;
                }
                else
                {
                    break;
                }
            }

            if (sIndex >= 0 && tIndex >= 0) // 都大于零才能判断
            {
                if (s[sIndex] != t[tIndex])
                {
                    return false;
                }
                else
                {
                    sIndex--;
                    tIndex--;
                }
            }
            else
            {
                if (sIndex >= 0 || tIndex >= 0) // 一正一负，字符串不相等
                {
                    return false;
                }
                break; // 都小于零，字符串相等，提前退出循环
            }
        }
        return true; // 上面都小于零已经退出了循环，字符串相等
    }
};