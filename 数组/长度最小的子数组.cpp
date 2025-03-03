#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0;           // 滑动窗口左边
        int result = INT32_MAX; // result先取一个最大值，用于后续不存在对应数组的判断
        int sum = 0;            // 滑动窗口的和

        for (int right = 0; right < nums.size(); right++) // right为滑动窗口右边，遍历整个数组
        {
            sum += nums[right]; // 窗口向右扩一个

            while (sum >= target) // 如果此时sum大于target，窗口左边缩小，优化窗口长度
            {
                int sublength = right - left + 1; // 需要先计算此时的长度
                result = result < sublength ? result : sublength;
                sum -= nums[left++]; // 窗口缩小
            }
        }
        // 如果还是INT32_MAX说明不存在
        return result == INT32_MAX ? 0 : result;
    }
};