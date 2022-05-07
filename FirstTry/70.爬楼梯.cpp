/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
// 100 %  44.89 %
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return n;
        int p = 0, q = 1, r = 2;
        for (int i = 3; i <= n; i++)
        {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};
// @lc code=end
// 100 %  5.42 %
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};