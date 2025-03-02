#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int sIndex = s.size() - 1, tIndex = t.size() - 1;
        int skipS = 0, skipT = 0;
        while (sIndex >= 0 || tIndex >= 0)
        {
            while (sIndex >= 0)
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

            while (tIndex >= 0)
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

            if (sIndex >= 0 && tIndex >= 0)
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
                if (sIndex >= 0 || tIndex >= 0)
                {
                    return false;
                }
                break;
            }
        }
        return true;
    }
};