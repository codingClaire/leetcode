/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
// 二刷
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0];
        for(int i=1;i<n;i++)
        {
            // 当前有股票肯定不会是冷冻期 上一时刻没操作 或者 当前买
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            // 1 当前没持有且在冷冻期 是因为上个时刻卖了股票
            f[i][1] = f[i - 1][0] + prices[i];
            // 2 当前没持有且没在冷冻期 是因为上一个时刻没有股票，处于或不处于冷冻期皆可能
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        // 最后一天手上还有股票显然是没意义的
        return max(f[n - 1][1], f[n - 1][2]);
    }
};
// @lc code=end
// 74.73 % 56.66%
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
        {
            return 0;
        }
        int n = prices.size();
        // 持有股票，对应的「累计最大收益」记为 f[i][0]
        // 不持有股票，处于冷冻期中，对应的「累计最大收益」记为 f[i][1]
        // 不持有股票，不处于冷冻期中，对应的「累计最大收益」记为 f[i][2]
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0];
        // 从1开始，这个细节很重要！！
        for (int i = 1; i < n; i++)
        {
            // 想每种情况倒退回去的来源
            // 0 当前持有股票，是因为上一个时刻没持有或者上个时刻没有股票不处于冷冻期，然后买入股票
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            // 1 当前没持有且在冷冻期 是因为上个时刻卖了股票
            f[i][1] = f[i - 1][0] + prices[i];
            // 2 当前没持有且没在冷冻期 是因为上一个时刻没有股票，处于或不处于冷冻期皆可能
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        // 最后一天手上还有股票显然是没意义的
        return max(f[n - 1][1], f[n - 1][2]);
    }
};