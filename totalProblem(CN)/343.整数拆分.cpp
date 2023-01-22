/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
// 100 % 94.08 %
class Solution
{
public:
    
    int integerBreak(int n)
    {
        vector<int> dp(60, 1);
        for(int i=3;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                // 注意这里tmp也要考虑j*(i-j)这种情况!!
                // 要两个取max才行
                int tmp = max(j*(i-j),dp[j]*(i-j));
                dp[i] = max(tmp, dp[i]);
            }
        }
        return dp[n];
    }
};
// @lc code=end
class Solution
{
public:
    int integerBreak(int n)
    {
        if (n <= 3)
        {
            return n - 1;
        }
        int quotient = n / 3;
        int remainder = n % 3;
        if (remainder == 0)
        {
            return (int)pow(3, quotient);
        }
        else if (remainder == 1)
        {// 余出一个4 
            return (int)pow(3, quotient - 1) * 4;
        }
        else
        {//余出一个2
            return (int)pow(3, quotient) * 2;
        }
    }
};