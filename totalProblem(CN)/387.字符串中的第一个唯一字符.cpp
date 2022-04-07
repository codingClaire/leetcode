/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
// 24.51 % 57.65 %
class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<int,int> mp;
        for(int i=0;i<s.length();i++)
        {
            if(mp.count(s[i]-'a'))
            {
                mp[s[i]-'a']++;
            }
            else
            {
                mp.insert(make_pair(s[i]-'a',1));
            }
        }
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]-'a']==1)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
// 24.51 % 57.65 %
class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++)
        {
            if (mp.count(s[i]))
            {
                mp[s[i]]++;
            }
            else
            {
                mp.insert(make_pair(s[i], 1));
            }
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (mp[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
