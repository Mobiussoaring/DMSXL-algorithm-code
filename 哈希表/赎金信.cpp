#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int m = ransomNote.size(), n = magazine.size();
        unordered_map<char, int> tem; // 用哈希表存magazine中字母和对应个数

        for (int i = 0; i < n; i++)
        {
            tem[magazine[i]]++;
        }

        for (int i = 0; i < m; i++)
        {
            tem[ransomNote[i]]--;
            if (tem[ransomNote[i]] < 0)
                return false;
        }
        return true;
    }
};