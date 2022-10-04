/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
// 方法二：数学  100.00% 97.79%
// 主要运用的是四平方和定理
// https://leetcode.cn/problems/perfect-squares/solution/wan-quan-ping-fang-shu-by-leetcode-solut-t99c/
class Solution
{
public:
    bool isPerfectSquare(int x)
    {
        int y=sqrt(x);
        return y*y==x;
    }
    bool CheckAnswer4(int x)
    {
        while(x%4 ==0)
            x/=4;
        return x%8 ==7;
    }
    int numSquares(int n)
    {
        if(isPerfectSquare(n))
            return 1;
        if(CheckAnswer4(n))
            return 4;
        for(int i=1;i*i<=n;i++)
        {
            int j=n-i*i;
            if(isPerfectSquare(j))
                return 2;
        }
        return 3;
    }
};
// @lc code=end
// 方法一：动态规划 83.16% 45.66%
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int minv = INT_MAX;
            // 小于i的每一个完全平方数j*j都会被枚举
            for (int j = 1; j * j <= i; j++)
            {
                minv = min(minv, f[i - j * j]);
            }
            // 要加1 是因为下限是1 当minv为0时，还是需要1的
            f[i] = minv + 1;
        }
        return f[n];
    }
};