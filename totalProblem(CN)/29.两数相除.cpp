/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
//[29] 两数相除
// 100.00% 52.63%
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        // remember this !! 
        if (divisor == INT_MIN)
            return dividend == INT_MIN ? 1 : 0;
        if (dividend == 0)
            return 0;
        int pos = 1;
        if (dividend > 0)
        {
            dividend = -dividend;
            pos = -pos;
        }
        if (divisor > 0)
        {
            divisor = -divisor;
            pos = -pos;
        }
        // 快速乘
        auto quickAdd = [](int divisor, int mid, int dividend)
        {
            // divisor 和 dividend 是负数，mid是正数
            // 需要判断 divisor * mid >= dividend 是否成立
            int result = 0, add = divisor;
            while (mid)
            {
                // 每次都看mid的最后一位
                // 如果是0 相当于对结果没有贡献（？
                if (mid & 1)
                {
                    // 如果最后一位是1，需要更新result，并且进行这个判断
                    // 需要保证 result + add >= 被除数
                    //为什么？ 因为result是负数，add也是负数
                    // 只有大于被除数，它们的绝对值的和才满足小于的情况，才可以继续
                    if (result < dividend -add) // 不要写成加法，会溢出！
                    {   //result和add的绝对值的和大于等于dividend
                        // 不用继续了
                        return false;
                    }
                    result += add;
                }
                if (mid != 1)
                {
                    // 需要保证 add + add >= 被除数
                    if (add < dividend - add) // 不要写成加法，会溢出！
                    {   // add + add的绝对值大于等于dividend 
                        // 不用继续了
                        return false;
                    }
                    add += add;
                }
                // 不能使用除法，mid除以2
                mid >>= 1;
            }
            return true;
        };

        int left = 1, right = INT_MAX, ans = 0;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            bool check = quickAdd(divisor, mid, dividend);
            if (check)
            {
                ans = mid;
                if (mid == INT_MAX)
                    break;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return pos * ans;
    }
};
// @lc code=end
