/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
// 100.00% 99.21%
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res = strs[0];
        int j = 0;
        int num = 1;
        if (strs.size() == 1)
            return res;
        while (j < res.size())
        {
            for (int i = 1; i < strs.size(); i++)
            {
                if (j > strs[i].length())
                {
                    continue;
                }
                if (strs[i][j] == res[j])
                {
                    num += 1;
                }
                else
                {
                    return res.substr(0, j);
                }
                if (num == strs.size())
                {
                    j++;
                    num = 0;
                }
            }
        }
        return res;
    }
};
// @lc code=end
