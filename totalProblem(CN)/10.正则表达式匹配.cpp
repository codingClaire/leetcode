/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
// 31.43 % 43.2 %
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int slen = s.size();
        int plen = p.size();
        auto matches = [&](int i, int j)
        {
            if (i == 0)
                return false;
            if (p[j - 1] == '.')
                return true;
            return s[i - 1] == p[j - 1];
        };
        vector<vector<int>> dp(slen + 1, vector<int>(plen + 1));
        dp[0][0] = true;
        // 可以这么理解，对每一个s中的字符，都要从头到尾过一遍p
        for (int i = 0; i <= slen; i++)
        {
            for (int j = 1; j <= plen; j++)
            {
                if (p[j- 1] == '*')
                {
                    // 匹配0次
                    dp[i][j] |= dp[i][j - 2];
                    // 匹配一次，看前一个就可以，相当于当前的i给扔了
                    if (matches(i, j - 1))
                        dp[i][j] |= dp[i - 1][j];
                }
                else
                {
                    if (matches(i, j))
                        dp[i][j] |= dp[i - 1][j - 1];
                }
            }
        }
        return dp[slen][plen];
    }
};
// @lc code=end
