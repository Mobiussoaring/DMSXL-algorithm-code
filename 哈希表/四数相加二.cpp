#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int n = nums1.size();
        unordered_map<int, int> tem; // 储存nums1和nums2两个数组所有和和个数的哈希表

        for (size_t i = 0; i < n; i++) // 遍历nums1和nums2得到所有和和个数
        {
            for (size_t j = 0; j < n; j++)
            {
                tem[nums1[i] + nums2[j]]++;
            }
        }

        int answer = 0;
        for (size_t i = 0; i < n; i++) // 找nums3+nums4是否有符合的
        {
            for (size_t j = 0; j < n; j++)
            {
                auto it = tem.find(-nums3[i] - nums4[j]);
                if (it != tem.end())
                {
                    answer += it->second;
                }
            }
        }
        return answer;
    }
};