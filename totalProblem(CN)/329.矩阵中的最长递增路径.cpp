/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
// 89.01 % 90.64 %
class Solution
{
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int row_size, col_size;

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        row_size = matrix.size();
        col_size = matrix[0].size();
        auto memo = vector<vector<int>>(row_size, vector<int>(col_size));
        int ans = 0;
        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < col_size; j++)
            {
                ans = max(ans, DFS(matrix, i, j, memo));
            }
        }
        return ans;
    }

    int DFS(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &memo)
    {
        // 已经搜索过了
        if (memo[row][col] != 0)
            return memo[row][col];
        // 初始化时加上它自己
        memo[row][col]++; // memo[row][col] = 1;
        for (int i = 0; i < 4; i++)
        {
            int new_row = row + dirs[i][0];
            int new_col = col + dirs[i][1];
            if (new_row >= 0 && new_row < row_size)
            {
                if (new_col >= 0 && new_col < col_size)
                {
                    // 新的位置在matrix里
                    if (matrix[new_row][new_col] > matrix[row][col])
                    {
                        // DFS + 动态规划 
                        // 记忆化搜索， 那个加1，因为要累记
                        memo[row][col] = max(memo[row][col], DFS(matrix, new_row, new_col, memo)+1);
                    }
                }
            }
        }
        return memo[row][col];
    }
};
// @lc code=end
