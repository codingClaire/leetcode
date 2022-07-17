/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
// [3] 无重复字符的最长子串 69.04 % 63.33 %
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        const int len = s.size();
        unordered_map<char, int> pos;
        int l = 0;
        int result = 0;
        for (int r = 0; r < len; r++)
        {
            //如果s[r]存在于unordered_map中
            if (pos.count(s[r]))
            {
                //更新left 向右移动到s[r]所在位置的下一个位置
                l = max(l, pos[s[r]] + 1);
            }
            //在map中插入(s[r],r)键值对
            pos[s[r]] = r;
            result = max(result, r - l + 1);
        }
        return result;
    }
};
// @lc code=end

// [3] 无重复字符的最长子串 50.54 % 41.6 %
//官方题解思路
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> st;
        int right = -1;
        int ans = 0;
        for (int left = 0; left < s.length(); left++)
        {
            if (left != 0)
                st.erase(s[left - 1]);
            while (right + 1 < s.length() && !st.count(s[right + 1]))
            {
                st.insert(s[right + 1]);
                right++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// previous solution
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        const int len = s.size();
        unordered_map<char, int> pos;
        int l = 0;
        int result = 0;
        for (int r = 0; r < len; r++)
        {
            if (pos.count(s[r])) //如果s[r]存在于unordered_map中 返回1
            {
                l = max(l, pos[s[r]] + 1); //更新left 向右移动到s[r]所在位置的下一个位置 因为已经出现过了嘛
            }
            pos[s[r]] = r;                   //设置s[r]
            result = max(result, r - l + 1); //求最大 保存好结果
        }
        return result;
    }
};