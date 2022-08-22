/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
//[289] 生命游戏
// 100.00 % 64.02 %
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int offset[3] = {0, 1, -1};
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int livenum = 0;
                // calculate the 1 number
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        if (offset[k] != 0 || offset[l] != 0)
                        {
                            int nexti = i + offset[k];
                            int nextj = j + offset[l];
                            if (0 <= nexti && nexti < m && 0 <= nextj && nextj < n && abs(board[nexti][nextj]) == 1)
                                livenum++;
                        }
                    }
                }
                if (board[i][j] == 1 && (livenum < 2 || livenum > 3))
                    board[i][j] = -1;
                if (board[i][j] == 0 && livenum == 3)
                    board[i][j] = 2;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] = board[i][j] > 0 ? 1 : 0;
            }
        }
    }
};
