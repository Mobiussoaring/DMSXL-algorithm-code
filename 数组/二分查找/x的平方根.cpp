#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            long square = long(middle) * middle;
            if (square < x) {
                left = middle + 1;
            }
            else if (square > x) {
                right = middle - 1;
            }
            else return middle;
        }
        return right;
    }
};