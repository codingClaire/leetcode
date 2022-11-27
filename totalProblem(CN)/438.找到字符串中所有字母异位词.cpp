/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
//  49.39 %   57.23 %
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        vector<int> sdic(26);
        vector<int> pdic(26);
        if (s.length() < p.length())
            return res;
        for (int i = 0; i < p.length(); i++)
        {
            pdic[p[i] - 'a']++;
            sdic[s[i] - 'a']++;
        }
        if (sdic == pdic)
            res.emplace_back(0);
        int left = 0, right = p.length();
        while (right < s.length())
        {
            sdic[s[left] - 'a']--;
            sdic[s[right] - 'a']++;
            if (sdic == pdic)
            {
                res.emplace_back(left + 1);
            }
            left++;
            right++;
        }
        return res;
    }
};
// @lc code=end
// 5.02 %  5.01 %
class Solution
{
public:
    vector<int> pdic = vector<int>(26);
    bool isValid(const string &s)
    {
        vector<int> sdic(26);
        for (int i = 0; i < s.length(); i++)
        {
            sdic[s[i] - 'a']++;
        }
        for (int i = 0; i < sdic.size(); i++)
        {
            if (pdic[i] != sdic[i])
            {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        for (int i = 0; i < p.length(); i++)
        {
            pdic[p[i] - 'a']++;
        }
        int left = 0, right = p.length() - 1;
        while (right < s.length())
        {
            string tmp = s.substr(left, right - left + 1);
            if (isValid(tmp))
            {
                res.emplace_back(left);
            }
            left++;
            right++;
        }
        return res;
    }
};