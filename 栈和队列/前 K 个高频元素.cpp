#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int> left, pair<int, int> right) {
            return left.second > right.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 使用哈希表储存元素的对应的频率
        unordered_map<int, int> fre;
        for (const auto& it : nums) {
            fre[it]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> prior;
        int tem = 0;
        for (const auto& it : fre) {
            // 当最小堆中元素数目不到k时，直接push
            if (tem < k) {
                prior.push(it);
                tem++;
            } else {
                // 只有大于的时候才push新的进去
                if (it.second > prior.top().second) {
                    prior.pop();
                    prior.push(it);
                }
            }
        }

        // 优先队列不能用迭代器遍历
        vector<int> answer;
        while (!prior.empty()) {
            answer.push_back(prior.top().first);
            prior.pop();
        }
        return answer;
    }
};