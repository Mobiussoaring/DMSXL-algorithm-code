#include <bits/stdc++.h>
using namespace std;

int main()
{
    string answer;
    int k;
    cin >> k;
    while (cin >> answer)
    {
    }

    reverse(answer.begin(), answer.end());       // 反转整个字符串
    reverse(answer.begin(), answer.begin() + k); // 反转前k个
    reverse(answer.begin() + k, answer.end());   // 反转前k个之后的
    cout << answer;
}