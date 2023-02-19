/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution
{
public:
    void reverse(string &s, int left, int right)
    {
        int len = right - left + 1;
        for (int i = 0; i < len / 2; i++)
            swap(s[left + i], s[left + len - 1 - i]);
    }

    string reverseStr(string s, int k)
    {
        int slen = s.length();
        int index = 0;
        while (index < slen)
        {
            int start_index = index;
            int end_index = min(start_index + k, slen) - 1;
            reverse(s, start_index, end_index);
            index += min(2 * k, slen - index);
        }
        return s;
    }
};
// @lc code=end

