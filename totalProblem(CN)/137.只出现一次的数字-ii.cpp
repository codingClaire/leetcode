/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
// @lc code=end

// 65.86 % 58.27 % 
// TODO: 数字电路
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // 答案的第 i个二进制位就是数组中所有元素的第 i 个二进制位之和除以 3的余数。
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            int total = 0;
            for (int j = 0; j < nums.size(); j++)
                total += ((nums[j] >> i) & 1);
            // 因为其他数都只出现3次，所以total%3不可能等于2的，只能是0或者1，机智吧
            if (total % 3)
            {
                // cout<<total<<" "<<total%3 <<endl;
                res |= (1 << i);
            }
        }
        return res;
    }
};