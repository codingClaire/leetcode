/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
// 100 % 38.37 %
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int slen = s.size();
        int plen = p.size();
        vector<vector<int>> dp(slen + 1, vector<int>(plen + 1, 0));
        dp[0][0] = 1;
        auto ismatch = [&](int i, int j)
        {
            if (i == 0)
                return false;
            if (p[j - 1] == '.')
                return true;
            return s[i - 1] == p[j - 1];
        };

        for (int i = 0; i <= slen; i++)
        {
            for (int j = 1; j <= plen; j++)
            {
                if (p[j - 1] != '*')
                {
                    // j-1不是*
                    // 就正常匹配就好
                    if (ismatch(i, j))
                        dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // j-1是*
                    // dp[i-1][j] 匹配一次当前的字符
                    // dp[i][j-2] 不匹配*，这样就是用当前的i去匹配j-2
                    if (ismatch(i, j - 1))
                        dp[i][j] = dp[i - 1][j] | dp[i][j - 2];
                    else
                        dp[i][j] = dp[i][j - 2];
                }
            }
        }
        return dp[slen][plen];
    }
};
// @lc code=end
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
                if (p[j - 1] == '*')
                {
                    // 匹配0次
                    // 相当于j-1就失效了，只看j-2就可以
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