/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
// [191] 位1的个数
// 100 % 23.61 %
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & (1 << i))
            {
                // 这里不能写成n&(1<<i)==1或者n&(1<<i)！=0
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

// 100 % 24.98 %
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        while (n)
        {
            n &= (n - 1);
            ans++;
        }
        return ans;
    }
};