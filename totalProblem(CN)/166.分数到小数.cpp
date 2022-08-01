/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
//[166] 分数到小数
// 100.00% 54.34%
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        // solve a/b
        string res;
        long a = numerator;
        long b = denominator;
        if (a % b == 0)
            res = to_string(a / b);
        else
        {
            // negative situation
            if (a < 0 ^ b < 0)
                res.push_back('-');
            a = abs(a);
            b = abs(b);
            // interger
            string intpart = to_string(a / b);
            res = res + intpart + ".";
            // decimal
            string fracpart;
            unordered_map<long, int> mp;
            long remainder = a % b;
            int index = 0;
            while (remainder != 0 && !mp.count(remainder))
            {
                mp[remainder] = index;
                remainder *= 10;
                fracpart += to_string(remainder / b);
                remainder %= b;
                index++;
            }
            //有循环节的情况,跳出时就会是循环节的第一个index
            if (remainder != 0)
            {
                int insert = mp[remainder];
                fracpart = fracpart.substr(0, insert) + '(' + fracpart.substr(insert) + ")";
            }
            res += fracpart;
        }

        return res;
    }
};
// @lc code=end
