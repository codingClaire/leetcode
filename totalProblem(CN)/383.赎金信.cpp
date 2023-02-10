/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < magazine.length(); i++)
        {
            mp[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.length(); i++)
        {
            if (!mp.count(ransomNote[i]))
                return false;
            mp[ransomNote[i]]--;
            if (mp[ransomNote[i]] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

