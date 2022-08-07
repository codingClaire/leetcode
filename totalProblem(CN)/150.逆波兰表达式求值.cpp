/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
//[150] 逆波兰表达式求值
// 97.77 % 54.45%
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> q;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == '+' || tokens[i] == '-' || tokens[i] == '*' || tokens[i] == '/')
            {
                int res;
                int a = q.top();
                q.pop();
                int b = q.top();
                q.pop();
                if (tokens[i] == '+')
                    res = a + b;
                else if (tokens[i] == '-')
                    res = a - b;
                else if (tokens[i] == '*')
                    res = a * b;
                else
                    res = a / b;
                q.push(res);
            }
            else
            {
                q.push(stoi(tokens[i]));
            }
        }
        return q.top();
    }
};
// @lc code=end
