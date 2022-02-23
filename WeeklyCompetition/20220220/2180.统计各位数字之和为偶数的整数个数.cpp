/*
 * @lc app=leetcode.cn id=2180 lang=cpp
 *
 * [2180] 统计各位数字之和为偶数的整数个数
 */

// @lc code=start
class Solution
{
public:
    int countEven(int num)
    {
        int ans = 0;
        if (num <= 9)
        {
            ans = num / 2;
        }
        else if (num <= 99)
        {
            ans += 4;
            int second = num / 10;
            int first = num % 10;
            ans += (second - 1) * 5;
            if (second % 2 == 0) //十位为偶数
                ans += first / 2 + 1;
            else
                ans += ceil(double(first) / 2);
        }
        else if (num <= 999)
        {
            ans = ans + 4 + 5 * 9;
            int third = num / 100;
            int second = (num % 100) / 10;
            int first = num - third * 100 - second * 10;
            ans += (third - 1) * 5 * 10;
            ans += second * 5;
            if ((second + third) % 2 == 0) //百位、十位为两偶或两奇
                ans += first / 2 + 1;      //偶数
            else
                ans += ceil(double(first) / 2); //奇数
        }
        else
        {
            ans = 4 + 9 * 5 + 9 * 50;
        }
        return ans;
    }
};

// @lc code=end
//Your runtime beats 100 % of cpp submissions
//Your memory usage beats 53.77 % of cpp submissions (5.8 MB)