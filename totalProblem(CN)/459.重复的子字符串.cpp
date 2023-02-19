/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution
{
public:
    bool kmp(const string &query, const string &pattern)
    {
        int n = query.size();
        int m = pattern.size();
        vector<int> next(m);
        for (int i = 1, j = 0; i < m; i++)
        {
            while (j > 0 && pattern[i] != pattern[j])
            {
                j = next[j - 1];
            }
            if (pattern[i] == pattern[j])
                j++;
            next[i] = j;
        }
        for (int i = 1, j = 0; i < n - 1; i++)
        {
            while (j > 0 && pattern[j] != query[i])
            {
                j = next[j - 1];
            }
            if (pattern[j] == query[i])
            {
                j++;
                if (j == m)
                    return true;
            }
        }
        return false;
    }

    bool repeatedSubstringPattern(string s)
    {
        return kmp(s + s, s);
    }
};
// @lc code=end
