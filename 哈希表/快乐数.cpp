#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> nums; // 储存平方和数是否已经出现过
        int square = pos_squre(n);

        while (nums.find(square) == nums.end()) // 当平方和数不重复时循环
        {
            if (square == 1)
                return true; // 有等于1的则为快乐数
            nums.insert(square);
            square = pos_squre(square);
        }
        return false;
    }

    int pos_squre(int num) // 求一个数各位的平方和
    {
        int ans = 0;
        int tem = 0;
        while (num != 0)
        {
            tem = num % 10;
            ans += tem * tem;
            num /= 10;
        }
        return ans;
    }
};