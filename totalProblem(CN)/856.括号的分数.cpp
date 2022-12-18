/*
 * @lc app=leetcode.cn id=856 lang=cpp
 *
 * [856] 括号的分数
 */

// @lc code=start
// 计算()的深度 100 % 90.76 %
class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int bal = 0, n = s.size(), res = 0;
        for (int i = 0; i < n; i++)
        {
            // 统计深度
            bal += (s[i] == '(' ? 1 : -1);
            // 找到()，就更新res
            if (s[i] == ')' && s[i - 1] == '(')
                res += 1 << bal;
        }
        return res;
    }
};
// @lc code=end
// 栈：  100 % 77.9 %
class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        stack<int> st; // 分数栈
        st.emplace(0);
        for (auto &c : s)
        {
            if (c == '(')
                st.emplace(0);
            else
            {
                int curscore = st.top();
                st.pop();
                // 只有curscore为0 才会有2*curscore < 1
                st.top() += max(2 * curscore, 1);
            }
        }
        return st.top();
    }
};