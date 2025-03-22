#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> tem;
        int n = s.size();
        tem.push(s[0]);

        for (int i = 1; i < n; i++) {
            if (!tem.empty() && s[i] == tem.top()) {
                tem.pop();
            } else {
                tem.push(s[i]);
            }
        }

        string answer;
        while (!tem.empty()) {
            answer.push_back(tem.top());
            tem.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};