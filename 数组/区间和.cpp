#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int length; // 数组长度
    vector<int> sum(length, 0); // 区间和数组
    cin >> length >> sum[0];

    int tem;
    for (int i = 1; i < length; i++)
    {
        cin >> tem;
        sum[i] = sum[i - 1] + tem; // 计算区间和
    }

    int a, b;
    while (cin >> a >> b)
    {
        if (a == 0) // 前面为零的时候要单独判断，不然会越界
            cout << sum[b] << "\n";
        else
            cout << sum[b] - sum[a - 1] << "\n";
    }
}