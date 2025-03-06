#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n, 0));    // 结果数组
        int num = 1;                                         // 填充的数字
        int left = 0, up = 0, right = n - 1, bottom = n - 1; // 左、上、右、下，代表对应位置填充开始地方
        // 按照从左向右、从上到下、从右向左、从下到上的顺序，每次都填充到边界
        while (num <= n * n)
        {
            for (int i = left; i <= right; i++)
                result[up][i] = num++;
            up++; // 填充完上层，up加一
            for (int i = up; i <= bottom; i++)
                result[i][right] = num++;
            right--; // 填充完右边，右边减一
            for (int i = right; i >= left; i--)
                result[bottom][i] = num++;
            bottom--; // 填充完下层，下层减一
            for (int i = bottom; i >= up; i--)
                result[i][left] = num++;
            left++; // 填充完左边，左边加一
        }
        return result;
    }
};