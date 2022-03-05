/*
 * @lc app=leetcode.cn id=2186 lang=cpp
 *
 * [2186] 使两字符串互为字母异位词的最少步骤数
 */

// @lc code=start
class Solution
{
public:
    int minSteps(string s, string t)
    {
        map<char, int> s_mp;
        map<char, int> t_mp;
        for (int i = 0; i < 26; i++)
        {
            s_mp.insert(make_pair('a' + i, 0));
            t_mp.insert(make_pair('a' + i, 0));
        }
        for (int i = 0; i < s.length(); i++)
        {
            s_mp[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            t_mp[t[i]]++;
        }
        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            char key = 'a' + i;
            res += abs(s_mp[key] - t_mp[key]);
        }
        return res;
    }
};
// @lc code=end
