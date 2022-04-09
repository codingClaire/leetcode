/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
// 90.54 % 64.5 %
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length()!=t.length())
            return false;
        vector<int> ch(26,0);
        for(int i=0;i<s.length();i++)
        {
            ch[s[i] - 'a']++;
        }
        for(int i=0;i<t.length();i++)
        {
            if (ch[t[i]-'a'] > 0)
                ch[t[i]-'a']--;
            else
                return false;
        }
        return true;
    }
};
// @lc code=end
// 26.19 % 69.1 %
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++)
        {
            if (!mp.count(s[i]))
                mp.insert(make_pair(s[i], 1));
            else
                mp[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            if (mp.count(t[i]) && mp[t[i]] != 0)
                mp[t[i]]--;
            else
                return false;
        }
        return true;
    }
};
