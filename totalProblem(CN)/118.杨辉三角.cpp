/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
//[118] 杨辉三角
// 100 % 81.28 %
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        vector<int> first = {1};
        ans.emplace_back(first);
        if (numRows == 1)
            return ans;
        for (int i = 2; i <= numRows; i++)
        {
            vector<int> cur;
            cur.emplace_back(1);
            for (int j = 0; j < ans[i - 2].size() - 1; j++)
            {
                cur.emplace_back(ans[i - 2][j] + ans[i - 2][j + 1]);
            }
            cur.emplace_back(1);
            ans.emplace_back(cur);
        }
        return ans;
    }
};
// @lc code=end
// 100 % 70.94 %
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        vector<int> first = {1};
        ans.emplace_back(first);
        if (numRows == 1)
            return ans;
        vector<int> second = {1, 1};
        ans.emplace_back(second);
        if (numRows == 2)
            return ans;
        for (int i = 3; i <= numRows; i++)
        {
            vector<int> cur;
            cur.emplace_back(1);
            for (int j = 0; j < ans[i - 2].size() - 1; j++)
            {
                cur.emplace_back(ans[i - 2][j] + ans[i - 2][j + 1]);
            }
            cur.emplace_back(1);
            ans.emplace_back(cur);
        }
        return ans;
    }
};