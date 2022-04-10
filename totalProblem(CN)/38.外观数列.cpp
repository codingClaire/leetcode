/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
// 76.63 % 23.96 %
class Solution
{
public:
    string num2description(string num)
    {
        // 12 -> 1-1 1-2 ->1112
        // 21 -> 2-1 1-1 -> 2111
        string de = "";
        vector<int> nums_mp(10, 0);
        int number_times = 1;
        for (int i = 0; i < num.length(); i++)
        {
            if ((num[i] - '0') != (num[i + 1] - '0'))
            {
                de.append(1, number_times + '0'); // times
                de.append(1, num[i]);             // character
                number_times = 1;
            }
            else
            {
                number_times++;
            }
        }
        return de;
    }
    string countAndSay(int n)
    {
        vector<string> numlist;
        numlist.emplace_back("1");
        for (int i = 1; i < n; i++)
        {
            string de = num2description(numlist[i - 1]);
            numlist.emplace_back(de);
        }
        return numlist[numlist.size() - 1];
    }
};
// @lc code=end
