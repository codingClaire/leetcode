/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
// 76.79 % 28.56 %
class Solution
{
public:
    int calculate(string s)
    {
        vector<int> v;
        int num = 0;
        char preSymbol = '+';
        for (int i = 0; i < s.length(); i++)
        {//看看这是怎么一次遍历的，看看这巧妙的写法
            if (isdigit(s[i]))
            {
                num = num * 10 + int(s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == s.length() - 1)
            {
                //当前是符号，或者当前是最后一个数字
                //判断前一个数字
                if (preSymbol == '+')
                    v.emplace_back(num);
                else if (preSymbol == '-')
                    v.emplace_back(-num);
                else if (preSymbol == '*')
                    v.back() *= num;
                else if (preSymbol == '/')
                    v.back() /= num;

                preSymbol = s[i];
                num = 0;
            }
        }
        // 最后v只剩下所有需要加起来的数
        return accumulate(v.begin(), v.end(), 0);
    }
};
// @lc code=end
