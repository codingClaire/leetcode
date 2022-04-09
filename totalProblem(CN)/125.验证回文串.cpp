/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
//改了tolower和isalnum函数后
// 88.4 %  80.19 %
class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.length() == 0)
            return true;
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = tolower(s[i]);
            if (s[j] >= 'A' && s[j] <= 'Z')
                s[j] = tolower(s[j]);
            if (!isalnum(s[i]))
            {
                i++;
                continue;
            }
            if (!isalnum(s[j]))
            {
                j--;
                continue;
            }
            if (s[i] != s[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};
// @lc code=end
// 23.92 % 9.89 %
class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.length() == 0)
            return true;
        string ns = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (isalnum(s[i]))
            {
                ns += tolower(s[i]);
            }
        }
        string revers(ns.rbegin(), ns.rend());
        return revers == ns;
    }
};

// 23.92 %  46.66 %
class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.length() == 0)
            return true;
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] - 'A' + 'a';
            if (s[j] >= 'A' && s[j] <= 'Z')
                s[j] = s[j] - 'A' + 'a';
            if (s[i] < '0' || (s[i] < 'a' && s[i] > '9') || s[i] > 'z')
            {
                i++;
                continue;
            }
            if (s[j] < '0' || (s[j] < 'a' && s[j] > '9') || s[j] > 'z')
            {
                j--;
                continue;
            }
            if (s[i] != s[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};