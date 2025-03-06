#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(); // 数组的维度
        int index = 0, nums = m * n; // index是返回数组的索引，储存matrix的值
        int left = 0, right = n - 1, up = 0, bottom = m - 1; // // 左、上、右、下，代表对应位置每层开始的地方
        vector<int> answer(nums, 0); // 结果矩阵

        // 按照从左向右、从上往下、从右往左、从下往上的顺序进行遍历
        // 注意，如果不是方阵的话需要在每个循环之后判断是否结束遍历，不然有些情况会数组越界
        while (index < nums)
        {
            for (int i = left; i <= right; i++) // 从左向右
                answer[index++] = matrix[up][i];
            up++; // 上层结束，加一
            if (index == nums)
                break;

            for (int i = up; i <= bottom; i++)
                answer[index++] = matrix[i][right];
            right--; // 右边层结束，减一
            if (index == nums)
                break;

            for (int i = right; i >= left; i--)
                answer[index++] = matrix[bottom][i];
            bottom--; // 下层结束，减一
            if (index == nums)
                break;

            for (int i = bottom; i >= up; i--)
                answer[index++] = matrix[i][left];
            left++; // 左边层结束，加一
        }
        return answer;
    }
};