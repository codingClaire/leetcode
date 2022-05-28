/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
//[268] 丢失的数字
// 93.42 %  39.21 %
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int supposev = (0 + n) * (n + 1) / 2;
        int totalv = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            totalv += nums[i];
        }
        return supposev - totalv;
    }
};
// @lc code=end
