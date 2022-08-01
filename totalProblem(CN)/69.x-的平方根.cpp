/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
//[69] x 的平方根
// 47.73% 52.31%
class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 0, r = x, ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end
// 6.11% 87.33%
class Solution
{
public:
    long long mySqrt(int x)
    {
        long long res = 1;
        if (x == 0)
            return 0;
        if (x <= 3)
            return 1;
        for (long long i = 2; i < x; i++)
        {
            if (i * i <= x && (i + 1) * (i + 1) > x)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};