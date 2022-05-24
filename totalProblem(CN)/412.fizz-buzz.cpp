/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
// [412] Fizz Buzz
// 100 % 78.22 %
class Solution
{
public:
    string num2string(int n)
    {
        string str;
        while (n != 0)
        {
            char bit = '0' + n % 10;
            str.insert(0, 1, bit);
            n = n / 10;
        }
        return str;
    }
    vector<string> fizzBuzz(int n)
    {
        vector<string> res;
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 && i % 5 == 0)
                res.emplace_back("FizzBuzz");
            else if (i % 3 == 0)
                res.emplace_back("Fizz");
            else if (i % 5 == 0)
                res.emplace_back("Buzz");
            else
            {
                string str = num2string(i);
                res.emplace_back(str);
            }
        }
        return res;
    }
};
// @lc code=end
