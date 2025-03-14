#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> sums; // 哈希表储存当前值和下标

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = sums.find(target - nums[i]); // 找target-nums[i]

            if (it != sums.end())
            {
                return {i, it->second};
            }
            sums[nums[i]] = i;
        }
        return {};
    }
};