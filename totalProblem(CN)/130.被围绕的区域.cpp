/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
// 94.86% 78.92%
class Solution
{
public:
    int m, n;
    void DFS(vector<vector<char>> &board, int row, int col)
    {
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'O')
            return;
        // 当前边上的O肯定不用变
        board[row][col] = 'A';
        // DFS找其他O，找不到的肯定不会被标记为A
        DFS(board, row + 1, col);
        DFS(board, row - 1, col);
        DFS(board, row, col + 1);
        DFS(board, row, col - 1);
    }

    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        if (m == 0)
            return;
        n = board[0].size();
        // 左右两列
        for (int i = 0; i < m; i++)
        {
            DFS(board, i, 0);
            DFS(board, i, n - 1);
        }
        // 上下两行
        for (int i = 0; i < n; i++)
        {
            DFS(board, 0, i);
            DFS(board, m - 1, i);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
// @lc code=end
