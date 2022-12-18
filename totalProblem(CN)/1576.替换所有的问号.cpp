/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
 */

// @lc code=start
// 34.19 % 92.65 %
class Solution
{
public:
    string modifyString(string s)
    {
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                for(char ch='a'; ch<='c';ch++)
                {
                    // 为何能写的如此优雅...
                    if((i>0 && s[i-1]==ch) ||(i<n-1 && s[i+1] == ch))
                        continue;
                    s[i] = ch;
                    break;
                }
            }
        }
        return s;
    }
};
// @lc code=end
// 0.74 % 38.97 %
class Solution
{
public:
    char getNewChar(string s, int i)
    {
        if (i == 0)
        {
            if (s[1] >= 'a' && s[1] <= 'z')
                return (s[1] - 'a' + 1) % 26 + 'a';
            return 'a';
        }
        else if (i == s.length() - 1)
        {
            if (s[i - 1] >= 'a' && s[i - 1] <= 'z')
                return (s[i - 1] - 'a' + 1) % 26 + 'a';
            return 'a';
        }
        else if (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i - 1] <= 'z')
        {
            if (abs(s[i + 1] - s[i - 1]) > 1)
                return min(s[i + 1], s[i - 1]) + abs(s[i + 1] - s[i - 1]) / 2;
            else
                return (max(s[i + 1], s[i - 1]) + 1 - 'a') % 26 + 'a';
        }
        else if (s[i - 1] >= 'a' && s[i - 1] <= 'z')
        {
            return (s[i - 1] - 'a' + 1) % 26 + 'a';
        }
        else
        {
            return (s[i + 1] + 1) % 26;
        }
    }

    string modifyString(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '?')
            {
                s[i] = getNewChar(s, i);
            }
        }
        return s;
    }
};