#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getnext(vector<int>& next, const string& s) {
        next.resize(s.size());
        int j = -1;
        next[0] = j;
        for (size_t i = 1; i < s.size(); i++) {
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1])
                j++;

            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;

        vector<int> next;
        getnext(next, needle);

        int j = -1;
        for (size_t i = 0; i < haystack.size(); i++) {
            while (j >= 0 && haystack[i] != needle[j + 1]) {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1])
                j++;

            if (j == needle.size() - 1)
                return (i - needle.size() + 1);
        }
        return -1;
    }
};