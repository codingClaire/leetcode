/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        string res = "";
        vector<string> v;
        string tmp = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                tmp += s[i];
            }
            else
            {
                if (tmp != "")
                    v.emplace_back(tmp);
                tmp = "";
            }
        }
        if (tmp != "" && tmp[0] != ' ')
            v.emplace_back(tmp);
        for (int i = v.size() - 1; i >= 0; i--)
            res += v[i] + ' ';
        return res.substr(0, res.size() - 1);
    }
};
// @lc code=end
// 100% 93.82%
class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start)
        {
            if (s[start] != ' ')
            {
                if (idx != 0)
                    s[idx++] = ' ';

                int end = start;
                while (end < n && s[end] != ' ')
                    s[idx++] = s[end++];

                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};