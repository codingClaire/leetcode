/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
// 87.51 %  83.68 %
class Solution
{
public:
    vector<string> res;

    void backtrack(string str, int start, int leftnum, int rightnum)
    {
        if (leftnum == 0 && rightnum == 0)
        {
            if (isValid(str))
                res.emplace_back(str);
            return;
        }

        // 线性的回溯过程，可以学习一下
        for (int i = start; i < str.size(); i++)
        {
            // 这里是为了去重，很机智
            if (i != start && str[i] == str[i - 1])
                continue;
            // 剩余的字符无法满足去掉字符数量的要求
            if (leftnum + rightnum > str.size() - i)
                return;
            // 注意看这个回溯怎么写的：
            if (leftnum > 0 && str[i] == '(')
                backtrack(str.substr(0, i) + str.substr(i + 1), i, leftnum - 1, rightnum);
            if (rightnum > 0 && str[i] == ')')
                backtrack(str.substr(0, i) + str.substr(i + 1), i, leftnum, rightnum - 1);
        }
    }

    vector<string> removeInvalidParentheses(string s)
    {
        int leftnum = 0;
        int rightnum = 0;
        //获取删除的左括号和右括号数
        for (auto &ch : s)
        {
            if (ch == '(')
            {
                leftnum++;
            }
            else if (ch == ')')
            {
                if (leftnum == 0)
                {
                    rightnum++;
                }
                else
                {
                    leftnum--;
                }
            }
        }
        backtrack(s, 0, leftnum, rightnum);
        return res;
    }
    // 判断字符串是否有效
    bool isValid(string &str)
    {
        int cnt = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
                cnt++;
            else if (str[i] == ')')
            {
                cnt--;
                if (cnt < 0)
                    return false;
            }
        }
        return cnt == 0;
    }
};
// @lc code=end
