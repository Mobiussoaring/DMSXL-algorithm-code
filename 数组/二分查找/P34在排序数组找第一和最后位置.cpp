#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = leftTarget(nums, target);
        int right = rightTarget(nums, target);
        return { first, right };
    }
private:
    int leftTarget(vector<int>& nums, int target) {
        int leftposition =
            -1; // the number of left position of target, -1 if not exist
        int left = 0, right = nums.size() - 1;
        while (left <= right) { 
            int middle = left + (right - left) / 2;
            if (target == nums[middle]) {
                right = middle - 1;    // search in the left part
                leftposition = middle; // update leftposition
            }
            else if (target < nums[middle]) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
        return leftposition;
    }

    int rightTarget(vector<int>& nums, int target) {
        int rightposition =
            -1; // the number of left position of target, -1 if not exist
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (target == nums[middle]) {
                rightposition = middle;
                left = middle + 1; // search in the right part
            }
            else if (target < nums[middle]) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
        return rightposition;
    }
};