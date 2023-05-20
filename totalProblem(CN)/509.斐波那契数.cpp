/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
// 100 %  23.5 %
class Solution 
{
public:
    int fib(int n) 
    {
        vector<int> dp(n+1,0);
        dp[0] = 0;
        if(n == 0)
            return dp[0];
        dp[1] = 1;
        if(n == 1)
            return dp[1];
        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
// @lc code=end

