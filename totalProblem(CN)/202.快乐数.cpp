/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
//[202] 快乐数
class Solution
{
public:
    int getSquareNum(int n)
    {
        int squareNum = 0;
        while (n != 0)
        {
            squareNum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return squareNum;
    }

    bool isHappy(int n)
    {
        set<int> st;
        while (n != 1 && !st.count(n))
        {
            st.insert(n);
            n = getSquareNum(n);
        }
        return n == 1;
    }
};
// @lc code=end
