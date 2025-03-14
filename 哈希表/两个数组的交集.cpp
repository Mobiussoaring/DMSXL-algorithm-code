#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> visited; // 记录nums1的所有元素
        vector<int> answers;
        for (size_t i = 0; i < nums1.size(); i++)
        {
            visited[nums1[i]] = 1; // 赋值为1表示未被访问
        }

        for (size_t i = 0; i < nums2.size(); i++)
        {
            auto it = visited.find(nums2[i]);
            if (it != visited.end() && it->second == 1)
            { // 有交集且未被访问过
                answers.push_back(it->first);
                it->second--;
            }
        }
        return answers;
    }
};