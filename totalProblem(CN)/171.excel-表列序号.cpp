/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
//[171] Excel 表列序号
// 100.00% 60.49%
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int number = 0;
        int length = columnTitle.length();
        long bit = 1;
        for (int i = length - 1; i >= 0; i--)
        {
            int curAlpha = columnTitle[i] - 'A' + 1;
            number += curAlpha * bit;
            bit *= 26;
        }
        return number;
    }
};
// @lc code=end
