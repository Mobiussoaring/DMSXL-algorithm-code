#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            int tem = num / middle;

            if (tem > middle) { // num is bigger than the square of middle 
                left = middle + 1;
            }
            else if (tem < middle) {
                right = middle - 1;
            }
            else if (tem == middle && num % middle == 0) {
                return true;
            }
            else {
                break; // the number don`t exist, tem=middle but num % middle != 0
            }
        }
        return false;
    }
};