/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */
// @lc code=start
// 29.07 % 52.45 %
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int xorsum = 0;
        for (int num : nums)
        {
            xorsum ^= num;
        }
        //防止溢出 -INT_MIN 超过INT_MAX了
        int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
        int type1 = 0;
        for (int num : nums)
        {
            //分成两组 这样就可以把两个数分开
            if (num & lsb)
                type1 ^= num;
        }
        // type2 可以直接用xorsum^type1计算得到
        return {type1, xorsum^type1};
    }
};
// @lc code=end
// 29.07 % 66.87 %
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int xorsum = 0;
        for (int num : nums)
        {
            xorsum ^= num;
        }
        // 防止溢出 -INT_MIN 超过INT_MAX了
        int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
        int type1 = 0, type2 = 0;
        for (int num : nums)
        {
            // 分成两组 这样就可以把两个数分开
            if (num & lsb)
                type1 ^= num;
            else
                type2 ^= num;
        }
        return {type1, type2};
    }
};