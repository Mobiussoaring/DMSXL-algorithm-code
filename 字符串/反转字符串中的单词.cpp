#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string answer;

        int left = s.size() - 1, right = s.size() - 1; // 左右指针，倒序遍历
        while (left >= 0 && right >= 0) {
            if (s[right] == ' ') { // 右指针找到单词的末尾
                right--;
            } else {
                left = right; // 左指针从单词末尾开始遍历
                while (left >= 0 && s[left] != ' ') {
                    left--;
                }
                answer.append(s.begin() + left + 1, s.begin() + right + 1);
                answer.push_back(' ');
                right = left;
            }
        }
        answer.erase(answer.size() - 1); // 删除多余的空格
        return answer;
    }
};