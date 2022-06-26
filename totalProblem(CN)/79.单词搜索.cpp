/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
//[79] 单词搜索
// 5.12 % 5.19 %
class Solution
{
public:
    bool backstract(vector<vector<char>> &board, vector<vector<int>> &isvisited,
                    string word, int index, int i, int j)
    {
        if (board[i][j] != word[index])
            return false;
        else if (index == word.length() - 1)
            return true;

        isvisited[i][j] = 1; // 已访问i,j
        vector<pair<int, int>> directions{
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (int d = 0; d < directions.size(); d++)
        {
            int nexti = i + directions[d].first;
            int nextj = j + directions[d].second;
            if (nexti >= 0 && nexti < board.size() && nextj >= 0 && nextj < board[0].size())
            {
                // (nexti,nextj)未被访问过
                if (!isvisited[nexti][nextj])
                {
                    bool nextflag = backstract(board, isvisited, word, index + 1, nexti, nextj);
                    if (nextflag)
                    {
                        result = true;
                        break;
                    }
                }
            }
        }
        isvisited[i][j] = 0; // 恢复，使得i,j未被访问
        return result;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<int>> isvisited(board.size(), vector<int>(board[0].size()));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                bool flag = backstract(board, isvisited, word, 0, i, j);
                if (flag)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

//[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
//"ABCB"