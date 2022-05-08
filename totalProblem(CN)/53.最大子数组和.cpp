/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
// [53] 最大子数组和
// 57.03 %  99.52 %
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = nums[0];
        int dp = 0; // dp数组可以只用一个值来存储
        for (int i = 0; i < nums.size(); i++)
        {
            dp = max(dp + nums[i], nums[i]);
            res = max(res, dp);
        }
        return res;
    }
};
// @lc code=end

// TODO:线段树解法
// https://leetcode-cn.com/problems/maximum-subarray/solution/zui-da-zi-xu-he-by-leetcode-solution/