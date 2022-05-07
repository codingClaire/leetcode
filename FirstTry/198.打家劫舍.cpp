/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
//24.64 %  22.12 % 
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int res = 0;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n);
        //dp[i] 表示前 i间房屋能偷到的最高总金额
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < n; i++)
        {
            // 两个选择：偷第i-1间房，或者偷第i间但不偷第i-1间
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
};
// @lc code=end
