/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
//[50] Pow(x, n)
// 100.00% 79.28%
class Solution
{
public:
    double myPow(double x, int n)
    {
        long long long_n = n;
        // INT_MIN的情况，如果直接转会变成INT_MAX+1,所以需要转成long long类型。
        double res = 1;
        if (long_n == 0 || x == 1.0)
            return res;
        else if (long_n < 0)
        {
            x = 1 / x;
            long_n = -1 * long_n;
        }
        double contribute = x;
        while (long_n > 0)
        {
            if (long_n % 2 == 1)
            {
                res *= contribute;
            }
            contribute *= contribute;
            long_n = long_n / 2;
        }
        return res;
    }
};
// @lc code=end
