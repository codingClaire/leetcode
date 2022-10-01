/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
// 动态规划法 52.64 %  17.7 %
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int slen = s.size();
        int plen = p.size();
        // dp[i][j] 表示字符串 s 的前 i个字符和模式 p的前j个字符是否能匹配
        vector<vector<int>> dp(slen + 1, vector<int>(plen + 1));
        dp[0][0] = true;
        //初始化
        for (int i = 1; i <= plen; i++)
        {
            if (p[i - 1] == '*')
                dp[0][i] = true;
            else
                break;
        }
        for (int i = 1; i <= slen; i++)
        {
            for (int j = 1; j <= plen; j++)
            {
                if (p[j - 1] == '*')
                {
                    //要么不用* ：dp[i][j - 1] 很好理解，就相当于空的
                    // 要么用*： dp[i - 1][j] 相当于*代表了被省略的s字符串的最后一个,在这之前的都不用看
                    //                          然后只需要看前一个就行，因为s字符串是顺序遍历的
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[slen][plen];
    }
};
// @lc code=end
