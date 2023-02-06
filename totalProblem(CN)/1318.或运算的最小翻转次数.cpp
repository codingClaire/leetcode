/*
 * @lc app=leetcode.cn id=1318 lang=cpp
 *
 * [1318] 或运算的最小翻转次数
 */

// @lc code=start
class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            int c_bit = (c >> i) & 1;
            int a_bit = (a >> i) & 1;
            int b_bit = (b >> i) & 1;
            int total = (a_bit << 2) + (b_bit << 1) + c_bit;
            if (total == 1 || total == 2 || total == 4)
                res++;
            else if (total == 6)
                res += 2;
        }
        return res;
    }
};
// @lc code=end
