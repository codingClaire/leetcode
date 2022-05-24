/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
//[13] 罗马数字转整数
// 23.26 % 56.12 %
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int len = s.length();
        int ans = mp[s[len - 1]];
        for (int i = len - 2; i >= 0; i--)
        {
            if (mp[s[i]] >= mp[s[i + 1]])
            {
                ans += mp[s[i]];
            }
            else
            {
                ans -= mp[s[i]];
            }
        }
        return ans;
    }
};
// @lc code=end
