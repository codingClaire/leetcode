/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
//[461] 汉明距离
// 100 % 96.6 %
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int ans = 0;
        int k = x ^ y;
        while(k)
        {
            k &=(k-1);
            ans++;
        }
        return ans;
    }
};
// @lc code=end
// 100 % 5.57 %
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int ans = 0;
        int k = x ^ y;
        return __builtin_popcount(k);
    }
};