#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;

        deque<int> window; // 滑动窗口
        for (int i = 0; i < nums.size(); i++) {
            if (!window.empty() &&
                (i - window.front()) == k) { // 是否移除窗口最后一个编号
                window.pop_front();
            }
            while (!window.empty() &&
                   nums[i] > nums[window.back()]) { // 弹出比当前新值小的编号
                window.pop_back();
            }
            window.push_back(i); // 压入新的编号
            if (i >= k - 1)
                answer.push_back(
                    nums[window.front()]); // 当窗口完全移入时才开始记录
        }
        return answer;
    }
};