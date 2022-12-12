/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
// 100 % 38.45 %
// 巧妙且有意思的做法
class Solution
{
public:
    int countDigitOne(int n)
    {
        long long mulk = 1;
        int ans = 0;
        while(n >= mulk)
        {
            ans += (n / (mulk * 10) * mulk + min(max(n % (mulk * 10) - mulk + 1, 0LL), mulk));
            mulk *= 10;
        }
        return ans;
    }
};
// @lc code=end
