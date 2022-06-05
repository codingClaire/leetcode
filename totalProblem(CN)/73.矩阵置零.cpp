/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
//  [73] 矩阵置零 34.38 % 89.35 %
//空间复杂度： O(1)
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        bool row0 = false, col0 = false;
        for (int i = 0; i < row; i++)
        {
            if (matrix[i][0] == 0)
                col0 = true;
        }
        for (int j = 0; j < col; j++)
        {
            if (matrix[0][j] == 0)
                row0 = true;
        }
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (matrix[i][j] == 0)
                    matrix[0][j] = matrix[i][0] = 0;
            }
        }
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (col0 == true)
        {
            for (int i = 0; i < row; i++)
                matrix[i][0] = 0;
        }
        if (row0 == true)
        {
            for (int j = 0; j < col; j++)
                matrix[0][j] = 0;
        }
    }
};
// @lc code=end
// 76.13 %  69.07 %
// 空间复杂度：O(m+n)
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> zero_row, zero_col;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    zero_row.emplace_back(i);
                    zero_col.emplace_back(j);
                }
            }
        }
        for (int i = 0; i < zero_row.size(); i++)
        {
            for (int j = 0; j < col; j++)
                matrix[zero_row[i]][j] = 0;
        }
        for (int j = 0; j < zero_col.size(); j++)
        {
            for (int i = 0; i < row; i++)
                matrix[i][zero_col[j]] = 0;
        }
    }
};