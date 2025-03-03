#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> answer(size, 0); // 结果数组

        int left = 0, right = size - 1, index = size - 1; // 从两边开始
        while (left <= right)
        {
            int squreL = nums[left] * nums[left];
            int squreR = nums[right] * nums[right];
            if (squreL <= squreR)
            {
                answer[index] = squreR;
                right--; // 右指针左移
                index--;
            }
            else // 左边大
            {
                answer[index] = squreL; 
                left++; // 左指针右移
                index--;
            }
        }
        return answer;
    }
};