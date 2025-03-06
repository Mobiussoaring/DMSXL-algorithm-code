#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int m, n;
    cin >> n >> m;
    // 初始化的时候比m，n大1，这样遍历数组的时候可以直接求二维前缀和
    vector<vector<int>> pre_sum(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) // 二维前缀和数组
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> pre_sum[i][j];
            pre_sum[i][j] = pre_sum[i][j] + pre_sum[i - 1][j] + pre_sum[i][j - 1] - pre_sum[i - 1][j - 1];
        }
    }

    int result = INT32_MAX;
    int sum = pre_sum[n][m];

    int tem = 0;
    for (int i = 1; i <= n; i++)
    {
        tem = abs(sum - pre_sum[i][m] - pre_sum[i][m]);
        result = result > tem ? tem : result;
    }

    tem = 0;
    for (int i = 1; i <= m; i++)
    {
        tem = abs(sum - pre_sum[n][i] - pre_sum[n][i]);
        result = result > tem ? tem : result;
    }
    cout<< result;
}