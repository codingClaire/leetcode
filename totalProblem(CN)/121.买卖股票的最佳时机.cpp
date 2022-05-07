/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
//[121] 买卖股票的最佳时机
//动态规划法
// 50.28 %  12.81 %
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int totalv = 0;
        int n = prices.size();
        if (n == 1)
            return 0;
        vector<int> dp_minv(n);
        vector<int> dp_totalv(n);
        dp_minv[0] = prices[0];
        dp_totalv[0] = prices[1] - dp_minv[0];
        for (int i = 1; i < n; i++)
        {
            dp_minv[i] = min(prices[i], dp_minv[i - 1]);
            dp_totalv[i] = max(dp_totalv[i - 1], prices[i] - dp_minv[i - 1]);
        }
        return max(dp_totalv[n - 1], 0);
    }
};
// @lc code=end
//[121] 买卖股票的最佳时机
// 41.33 %  52.99 %
// 一次遍历法
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int totalv = 0;
        int minv = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            if (minv > prices[i])
                minv = prices[i];
            int curv = prices[i] - minv;
            if (curv > totalv)
                totalv = curv;
        }
        return totalv;
    }
};