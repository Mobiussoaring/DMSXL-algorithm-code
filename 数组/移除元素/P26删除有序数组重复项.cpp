#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1, size = nums.size(); // slow为慢指针
        if (size == 1) return 1; // 只有一个数

        for (int fast = 1; fast < size; fast++) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};