/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
//  100 %   43 %
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int higher_bit = 1;
        int len = digits.size();
        for (int i = len - 1; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                digits[i]++;
                for (int j = len - 1; j > i; j--)
                    digits[j] = 0;
                return digits;
            }
        }
        vector<int> res(len + 1); // all 9 situation
        res[0] = 1;
        return res;
    }
};
// @lc code=end
//  100 %   58.32 %
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int higher_bit = 1;
        int len = digits.size();
        for (int i = len - 1; i >= 0; i--)
        {
            int total_sum = digits[i] + higher_bit;
            digits[i] = (total_sum) % 10;
            higher_bit = (total_sum) / 10;
        }
        if (higher_bit == 1)
            digits.insert(digits.begin(), higher_bit);
        return digits;
    }
};