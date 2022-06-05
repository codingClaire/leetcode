/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
// [5] 最长回文子串 26.59 % 52.61 %
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        int maxLen = 1;
        int startPos = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        for (int len = 2; len <= n; len++)
        {
            for (int left = 0; left < n; left++)
            {
                int right = left + len - 1;
                if (right >= n)
                    break;
                if (s[left] != s[right])
                {
                    dp[left][right] = false;
                }
                else
                {
                    if (right - left < 3)
                        dp[left][right] = true;
                    else
                        dp[left][right] = dp[left + 1][right - 1];
                }
                if (dp[left][right] && right - left + 1 > maxLen)
                {
                    maxLen = right - left + 1;
                    startPos = left;
                }
            }
        }
        return s.substr(startPos, maxLen);
    }
};
// @lc code=end
