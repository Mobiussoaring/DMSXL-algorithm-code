#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result; // 结果数组
        int n = nums.size();
        sort(nums.begin(), nums.end()); // 排序后好处理
        if (n < 4)
            return result;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > target && nums[i] > 0) // 剪枝
                break;

            if (i > 0 && nums[i] == nums[i - 1]) // 跳过与上轮重复的值
                continue;

            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) // 剪枝
                    break;

                if (j > i + 1 && nums[j] == nums[j - 1]) // 跳过与上轮重复的值
                    continue;

                int left = j + 1, right = n - 1; // 双指针遍历
                while (left < right)
                {
                    if (long(nums[i]) + nums[j] + nums[left] + nums[right] <
                        target)
                    {
                        left++;
                    }
                    else if (long(nums[i]) + nums[j] + nums[left] +
                                 nums[right] >
                             target)
                    {
                        right--;
                    }
                    else
                    {
                        result.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};