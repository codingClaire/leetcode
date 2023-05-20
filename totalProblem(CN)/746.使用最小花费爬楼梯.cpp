/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
// 85.91 % 5.18 %
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n+1,0); // 要看dp[n]才是终点！！
        dp[0] = 0; //第一步不需要体力，所以是0
        dp[1] = 0; // 第一步不需要体力，所以是0
        for(int i=2;i<=n;i++)
        {
            // dp写对了，nice
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};
// @lc code=end
