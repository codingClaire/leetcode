/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
// 99.13 %  82.62 %
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int slen = s.size();
        char tmp;
        for (int i = 0; i < slen / 2; i++)
        {
            tmp = s[i];
            s[i] = s[slen - 1 - i];
            s[slen - 1 - i] = tmp;
        }
    }
};
// @lc code=end

// 79.42 %57.58 %
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }
};

// 79.42 % 16.24%
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int slen = s.size();
        for (int i = 0; i < slen / 2; i++)
        {
            swap(s[i], s[slen - 1 - i]);
        }
    }
};