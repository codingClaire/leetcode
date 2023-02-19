/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size(), m = needle.size();
        if (m == 0)
            return 0;
        vector<int> next(m); // next数组
        // next[0] 只有一个字符，肯定是0
        for (int i = 1, j = 0; i < m; i++)
        { // 回退j， 可以理解为j永远维护着相等的前后缀的后一个字符
            //[0,j) 是最大相同的前后缀
            while (j > 0 && needle[i] != needle[j])
                j = next[j - 1];
            // 比对当前的新的i
            if (needle[i] == needle[j])
                j++;
            next[i] = j;
        }
        for (int i = 0, j = 0; i < n; i++)
        {
            // 和求next数组非常相似
            while (j > 0 && haystack[i] != needle[j])
                j = next[j - 1];
            if (haystack[i] == needle[j])
                j++;
            if (j == m)
                return i - m + 1;
        }
        return -1;
    }
};
// @lc code=end
// 暴力法  32.78% 85.53%
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size(), m = needle.size();
        // haystack开始的字符
        for (int i = 0; i + m <= n; i++)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return i;
        }
        return -1;
    }
};