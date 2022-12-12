/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) 
        {
            return 0;
        }
        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns));
        //  dp[i][j] 代表的是，以坐标点(i,j) 为右下角的最大正方形
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < columns; j++) 
            {
                if (matrix[i][j] == '1') 
                {
                    // 边界条件！ 
                    if (i == 0 || j == 0) 
                    {
                        dp[i][j] = 1;
                    } 
                    else 
                    {// 这能想出来?  TODO: 1277
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }
};
// @lc code=end
// [["0","1"],["0","1"]]
// [["1","1","1","1","1","1","1"]]
// 暴力总会TLE
class Solution
{
public:
    bool check(int curlen, int row, int col, vector<vector<char>> &matrix)
    {
        for (int i = 0; i < curlen + 1; i++)
        {
            if (matrix[row + curlen][col + i] == '0')
                return false;
        }
        for (int i = 0; i < curlen + 1; i++)
        {
            if (matrix[row + i][col + curlen] == '0')
                return false;
        }
        return true;
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {
        int rownum = matrix.size();
        int colnum = matrix[0].size();
        int res = 0;
        for (int i = 0; i < rownum; i++)
        {
            if(res == rownum || res == colnum)
                return res * res;
            for (int j = 0; j < colnum; j++)
            {
                if (matrix[i][j] == '1')
                {
                    int curlen = 0;
                    while (i + curlen <= matrix.size() - 1 && j + curlen <= matrix[0].size() - 1 && check(curlen, i, j, matrix) == true)
                    {
                        curlen++;
                    }
                    res = max(res, curlen);
                }
            }
        }
        return res * res;
    }
};