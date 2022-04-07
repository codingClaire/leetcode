/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
// 42.09% 5.03%
class Solution
{
public:
    int reverse(int x)
    {
        long res = 0;
        vector<int> digits;
        long num = 10;
        while (x != 0)
        {
            digits.emplace_back(x % num / (num / 10));
            x = x - x % num;
            num *= 10;
        }
        num /= 10;
        for (int i = 0; i < digits.size(); i++)
        {
            num /= 10;
            res += digits[i] * num;
        }
        if (res > INT_MAX || res < INT_MIN)
            return 0;
        return res;
    }
};
// @lc code=end

