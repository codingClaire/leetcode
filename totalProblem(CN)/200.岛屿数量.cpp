/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
// [200] 岛屿数量 58.81 %  89.21 %
class Solution
{
public:
    void DFS(vector<vector<char>> &grid, int i, int j)
    {
        int row = grid.size();
        int col = grid[0].size();

        grid[i][j] = '0';
        if (i - 1 >= 0 && grid[i - 1][j] == '1')
            DFS(grid, i - 1, j);
        if (i + 1 < row && grid[i + 1][j] == '1')
            DFS(grid, i + 1, j);
        if (j - 1 >= 0 && grid[i][j - 1] == '1')
            DFS(grid, i, j - 1);
        if (j + 1 < col && grid[i][j + 1] == '1')
            DFS(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int row = grid.size();
        if (row == 0)
            return 0;
        int col = grid[0].size();
        int res = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    DFS(grid, i, j);
                }
            }
        }
        return res;
    }
};
// @lc code=end