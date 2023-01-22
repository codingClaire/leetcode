/*
 * @lc app=leetcode.cn id=1293 lang=cpp
 *
 * [1293] 网格中的最短路径
 */
// @lc code=start
// 终于AC了， DFS + 三维状态存储
// 5.19 % 5.2 %
class Solution
{
public:
    void dfs(int i, int j, int endi, int endj, int k, int tmp, vector<int> &res, vector<vector<int>> &grid,vector<vector<vector<int>>>& step)
    {
        if (i < 0 || j < 0 || i > endi || j > endj)
            return;
        if (k < 0 && (i != endi || j != endj))
            return;
        if (tmp >= step[i][j][k])
            return;
        if (k >= 0 && i == endi && j == endj)
        {
            res.emplace_back(tmp);
            return;
        }
        step[i][j][k] = tmp;  
        vector<int> di = {0, 0, 1, -1};
        vector<int> dj = {1, -1, 0, 0};
        for (int d = 0; d < 4; d++)
        {
            int curi = i + di[d];
            int curj = j + dj[d];
            if (curi >= 0 && curi <= endi && curj >= 0 && curj <= endj)
            {
                if (grid[curi][curj] == 0)
                    dfs(curi, curj, endi, endj, k, tmp + 1, res, grid,step);
                else
                    dfs(curi, curj, endi, endj, k - 1, tmp + 1, res, grid,step);
            }
                
        }
    }

    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int starti = 0, startj = 0;
        int endi = grid.size() - 1, endj = grid[0].size() - 1;
        vector<int> res;
        if (k > endi + endj)
            return endi+endj;
        vector<vector<vector<int>>> step(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k + 1, INT_MAX)));
        dfs(starti, startj, endi, endj, k, 0, res, grid,step);
        if (res.size() == 0)
            return -1;
        int minres = res[0];
        for (int i = 1; i < res.size(); i++)
        {
            if (res[i] < minres)
                minres = res[i];
        }
        return minres;
    }
};
