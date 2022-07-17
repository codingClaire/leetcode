/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
//[322] 零钱兑换
// 37 % 73.85 %
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int maxcoin = amount + 1;
        vector<int> dp(amount + 1, maxcoin);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < (int)coins.size(); j++)
            {
                if (i >= coins[j])
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
// @lc code=end
