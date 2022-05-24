/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */

// @lc code=start
// 97.82 % 55.76 %
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        return n > 0 && 1162261467 % n == 0;
    }
};
// @lc code=end

// 11.32 %  36.81 %
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        while (n && n % 3 == 0)
        {
            n = n / 3;
        }
        return n == 1;
    }
};