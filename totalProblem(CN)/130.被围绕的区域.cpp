/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
// BFS   32.56 % 46.99 %
class Solution
{
public:
    const int dx[4] = {1,-1,0,0};
    const int dy[4] = {0,0,1,-1};
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();

        queue<pair<int,int>> que;
        for(int i=0;i<n;i++)
        {
            if(board[i][0] == 'O')
            {
                que.emplace(i,0);
                board[i][0] = 'A';
            }
            if (board[i][m-1] == 'O')
            {
                que.emplace(i, m-1);
                board[i][m-1] = 'A';
            }
        }
        for (int i = 1; i < m - 1; i++)
        {
            if (board[0][i] == 'O')
            {
                que.emplace(0, i);
                board[0][i] = 'A';
            }
            if (board[n - 1][i] == 'O')
            {
                que.emplace(n - 1, i);
                board[n - 1][i] = 'A';
            }
        }
        while(!que.empty())
        {
            int x = que.front().first, y = que.front().second;
            que.pop();
            for(int i=0;i<4;i++)
            {
                int mx = x+dx[i], my = y+dy[i];
                if (mx < 0 || my < 0 || mx >= n || my >= m || board[mx][my] != 'O')
                {
                    continue;
                }
                que.emplace(mx, my);
                board[mx][my] = 'A';
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
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

// DFS二刷95.94 % 42.42 %
class Solution
{
public:
    void DFS(vector<vector<char>> &board, int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i > n - 1 || j > m - 1 || board[i][j] != 'O')
            return;
        board[i][j] = 'A';
        // 没有和边界的O相连的，是不会被标记的，其实就是最终应该被标记的
        DFS(board, i + 1, j, m, n);
        DFS(board, i - 1, j, m, n);
        DFS(board, i, j + 1, m, n);
        DFS(board, i, j - 1, m, n);
    }

    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();
        // 所有的不被包围的 O 都直接或间接与边界上的 O 相连！！！
        // 所以DFS只需要从边界开始的就可以了
        for (int i = 0; i < n; i++)
        {
            DFS(board, i, 0, m, n);
            DFS(board, i, m - 1, m, n);
        }
        for (int i = 1; i < m - 1; i++)
        {
            DFS(board, 0, i, m, n);
            DFS(board, n - 1, i, m, n);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
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