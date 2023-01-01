/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
// 37.94 % 13.78 %
class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        vector<int> candi = {2, 3, 5};
        bool flag = 0;
        while (n > 1)
        {
            flag = false;
            for (int i = 0; i < 3; i++)
            {
                if (n % candi[i] == 0)
                {
                    flag = true;
                    n = n / candi[i];
                    break;
                }
            }
            if (flag == false)
                return false;
        }
        return true;
    }
};
// @lc code=end
