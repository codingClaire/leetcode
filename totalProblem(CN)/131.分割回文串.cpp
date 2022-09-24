/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
// 78.47 %  66.87 %
class Solution
{
private:
    int n;
    vector<vector<int>> dp;     // 二维动态规划数组
    vector<vector<string>> res; // 最终解
    vector<string> tmp;         // 单个的解，回溯中会反复使用
public:
    void DFS(const string &s, int i)
    {
        if (i == n)
        {
            res.emplace_back(tmp);
            return;
        }
        // 从当前开始，到字符串末尾
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(s, i, j) == 1)
            {
                // 放入i到j
                tmp.emplace_back(s.substr(i, j - i + 1));
                // 回溯函数跳到j+1开始
                DFS(s, j + 1);
                // 弹出i到j
                tmp.pop_back();
            }
        }
    }
    // 记忆化搜索
    // TODO: dp[i][j] = 0 表示未搜索，1 表示是回文串，-1 表示不是回文串
    int isPalindrome(const string &s, int i, int j)
    {
        if (dp[i][j])
            return dp[i][j];
        if (i >= j)
            return dp[i][j] = 1;
        return dp[i][j] = (s[i] == s[j] ? isPalindrome(s, i + 1, j - 1) : -1);
    }

    vector<vector<string>> partition(string s)
    {
        n = s.size();
        // dp全部初始化为0，表示未访问
        dp.assign(n, vector<int>(n));

        DFS(s, 0);
        return res;
    }
};
// @lc code=end
//方法一：回溯 + 动态规划预处理
// 61.78 % 54.47 %
class Solution
{
private:
    int n;
    vector<vector<int>> dp;     // 二维动态规划数组
    vector<vector<string>> res; // 最终解
    vector<string> tmp;         // 单个的解，回溯中会反复使用
public:
    void DFS(const string &s, int i)
    {
        if (i == n)
        {
            res.emplace_back(tmp);
            return;
        }
        // 从当前开始，到字符串末尾
        for (int j = i; j < n; j++)
        {
            if (dp[i][j])
            {
                // 放入i到j
                tmp.emplace_back(s.substr(i, j - i + 1));
                // 回溯函数跳到j+1开始
                DFS(s, j + 1);
                // 弹出i到j
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        n = s.size();
        dp.assign(n, vector<int>(n, true));
        // 双指针
        // dp[i][j]表示s[i...j]是否是回文串
        // s[i,i]肯定是true
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
        // 要在用动态规划确定了回文串的位置之后，才可以用回溯的算法
        DFS(s, 0);
        return res;
    }
};