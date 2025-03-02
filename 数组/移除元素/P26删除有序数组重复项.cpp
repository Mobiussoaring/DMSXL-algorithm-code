#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1, size = nums.size(); // slowΪ��ָ��
        if (size == 1) return 1; // ֻ��һ����

        for (int fast = 1; fast < size; fast++) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};