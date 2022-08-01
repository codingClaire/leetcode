/*
* @lc app=leetcode.cn id=172 lang=cpp
*
* [172] 阶乘后的零
*/

// @lc code=start
//[172] 阶乘后的零
// 28.68% 86.18%
class Solution
{
public:
    int trailingZeroes(int n)
    {
        //质因数为5的个数不会大于质因数为2的个数，所以不需要min(twoNum,fiveNum)
        //只需要找到1-n的每个数的5的因子个数再相加即可
        int res = 0;
        for (int num = 5; num <= n; num += 5)
        {
            for (int i = num; i % 5 == 0; i /= 5)
            {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
