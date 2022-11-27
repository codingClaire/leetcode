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
                    if (right - left < 3) // right-1 -(left+1) -1 <2 不需要判断
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

// 二刷，自己写
class Solution
{
public:
    int getLen(string s, int left, int right)
    {
        while (left >= 0 && right <= s.length() - 1 && s[left] == s[right])
        {
            left--, right++;
        }
        return right - left - 1;
    }

    string longestPalindrome(string s)
    {
        int len = s.length();
        int maxPoint, maxRes = 0;
        for (int l = 0; l < len; l++)
        {
            int oddlen = getLen(s, l, l);
            int evenlen = getLen(s, l, l + 1);
            int maxlen = max(oddlen, evenlen);
            if (maxRes < maxlen)
            {
                maxPoint = l;
                maxRes = maxlen;
            }
        }
        int maxLeft = maxRes % 2 == 0 ? maxPoint - (maxRes / 2 - 1) : maxPoint - maxRes / 2;
        return s.substr(maxLeft, maxRes);
    }
};

// 中心扩展的题解代码

class Solution
{
public:
    pair<int, int> expandAroundCenter(const string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};