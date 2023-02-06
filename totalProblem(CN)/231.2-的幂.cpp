/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
// 36.17 % 60.18 %
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return n>0 && (n & (n-1)) == 0;
    }
};
// @lc code=end
// 36.17 %  5.44 %
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;
        while (n > 1 && n % 2 == 0)
        {
            n = n / 2;
        }
        if (n == 0 || n == 1)
            return true;
        return false;
    }
};