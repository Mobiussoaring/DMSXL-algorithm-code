#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size(); // 数组长度
        sort(nums.begin(), nums.end()); // 对数组排序
        vector<vector<int>> answer; // 结果数组

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0) // 已排序，如果大于零，后面肯定没有符合的
                return answer;
            if (i > 0 && nums[i] == nums[i - 1]) // i - 1避免漏掉类似-1 -1 2的情况
                continue;

            int left = i + 1, right = n - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    answer.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) // 注意还要有left<right的条件，不然会越界（如000）
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++; // 还要再移动一个，因为是到相同的数的最后一个
                    right--;
                }
            }
        }
        return answer;
    }
};