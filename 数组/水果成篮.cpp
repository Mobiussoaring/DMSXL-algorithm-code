#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int result = 0;
        int left = 0;                // 左指针
        unordered_map<int, int> cof; // 记录窗口内水果的情况
        for (int right = 0; right < fruits.size(); right++)
        {
            cof[fruits[right]]++; // 右指针移动，加入水果
            while (cof.size() > 2)
            { // 如果种类大于2，移除左指针的水果，直到种类小于等于2
                auto it = cof.find(fruits[left]);
                it->second--;
                if (it->second == 0)
                { // 当一种水果减少为0，从哈希表中删除
                    cof.erase(it);
                }
                left++; // 移动左指针
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};