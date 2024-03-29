/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
// 动态规划 30.32 %  20.15 % 
// TODO: 没看懂题解
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = accumulate(stones.begin(), stones.end(), 0); // 石头的总重量
        int n = stones.size(), m = sum/2; // 背包容量m 物品个数n，第i个物品的重量和价值都是stones[i]
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        dp[0][0] = true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(j<stones[i])
                    dp[i+1][j] = dp[i][j];
                else
                    dp[i+1][j] = dp[i][j] || dp[i][j-stones[i]];
            }
        }
        for(int j=m;;--j)
        {
            if(dp[n][j])
                return sum-2*j;
        }
    }
};
// @lc code=end
