/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
// [22] 括号生成
// 100 % 72.61 %
class Solution
{
public:
    void backtrack(vector<string> &res, string &tmp, int n, int left, int right)
    {
        if (tmp.length() == n * 2)
        {
            res.emplace_back(tmp);
        }
        if (left < n)
        {
            tmp.push_back('(');
            backtrack(res, tmp, n, left + 1, right);
            tmp.pop_back();
        }
        if (right < left)
        {
            tmp.push_back(')');
            backtrack(res, tmp, n, left, right + 1);
            tmp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string tmp;
        backtrack(res, tmp, n, 0, 0);
        return res;
    }
};
// @lc code=end

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string s = "";
        backtrack(res, n, n, s, "");
        return res;
    }

    void backtrack(vector<string> &res, int left, int right, string s, string s_append)
    {
        s.append(s_append);
        if (left == 0 && right == 0)
        {
            res.push_back(s);
            return;
        }
        if (left > right)
        { //符合括号的规则
            return;
        }
        if (left > 0)
        {
            backtrack(res, left - 1, right, s, "(");
        }
        if (right > 0)
        {
            backtrack(res, left, right - 1, s, ")");
        }
    }
};