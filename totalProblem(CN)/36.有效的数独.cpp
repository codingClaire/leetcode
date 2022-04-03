/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
// 93.74 %  73.83 %
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int box[9][9] = {0};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '1';
                    int boxidx = (i / 3) * 3 + j / 3;
                    if (col[j][num] == 1 || row[i][num] == 1 || box[boxidx][num] == 1)
                        return false;
                    col[j][num]++;
                    row[i][num]++;
                    box[boxidx][num]++;
                }
            }
        }
        return true;
    }
};
// @lc code=end
