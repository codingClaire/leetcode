/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start
// Dijkstra算法 75.08 % 70.51 %
class Solution
{
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        auto tupleCmp= [](const auto& e1, const auto& e2)
        {
            auto&& [x1,y1,d1] = e1;
            auto&& [x2,y2,d2] = e2;
            return d1>d2;
        };

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, decltype(tupleCmp)> q(tupleCmp);
        q.emplace(0,0,0);
        vector<int> dist(m*n, INT_MAX);
        dist[0] = 0;
        vector<int> seen(m*n);
        while(!q.empty())
        {
            auto [x,y,d] = q.top();
            q.pop();
            int id = x*n+y;
            if(seen[id])
                continue;
            if(x == m-1 && y == n-1)
                break;
            seen[id] =1;
            for (auto &dir : dirs)
            {
                int curx = x + dir[0];
                int cury = y + dir[1];
                if (curx >= 0 && curx < m && cury >= 0 && cury < n 
                && max(d, abs(heights[x][y] - heights[curx][cury])) < dist[curx * n + cury])
                {
                    dist[curx * n + cury] = max(d, abs(heights[x][y] - heights[curx][cury]));
                    q.emplace(curx,cury,dist[curx*n+cury]);
                }
            }
        }
        return dist[m*n-1];
    }
};
// @lc code=end

// BFS + 二分查找： 19.15 % 17.96 %
// 是否存在一条从左上角到右下角的路径，其经过的所有边权的最大值不超过 x
class Solution
{
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        int left = 0, right = 999999, ans = 0;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            queue<pair<int, int>> q;
            q.emplace(0, 0);
            // 每次查找的时候，会重新生成一个全0的seen
            vector<int> seen(m * n);
            seen[0] = 1;
            while (!q.empty())
            {
                auto [x, y] = q.front(); // 还能这样写，机智
                q.pop();
                for (auto &d : dir)
                {
                    int curx = x + d[0];
                    int cury = y + d[1];
                    if (curx >= 0 && curx < m && cury >= 0 && cury < n && !seen[curx * n + cury] && abs(heights[x][y] - heights[curx][cury]) <= mid)
                    {
                        q.emplace(curx, cury);
                        seen[curx * n + cury] = 1;
                    }
                }
            }
            // 最后一个格子到达了，收缩右侧
            if (seen[m * n - 1])
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};

// 错错错，DFS不能这样写，递归也不能用unseen
/*
class Solution
{
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>> &heights, int i, int j, int maxheight, int &minres, vector<int> &unseen)
    {
        int m = heights.size(), n = heights[0].size();
        if (unseen[i * n + j] == 1)
            return;
        if (i < 0 || i > m - 1 || j < 0 || j > n - 1)
            return;
        if (i == m - 1 && j == n - 1)
        {
            cout << i << " " << j << " " << maxheight << endl;
            minres = min(maxheight, minres);
            return;
        }
        unseen[i * n + j] = 1;
        cout << i << " " << j << endl;
        for (auto &d : dir)
        {
            int curi = i + d[0];
            int curj = j + d[1];
            if (curi < 0 || curi > m - 1 || curj < 0 || curj > n - 1)
                return;
            maxheight = max(maxheight, abs(heights[i][j] - heights[curi][curj]));
            dfs(heights, curi, curj, maxheight, minres, unseen);
        }
    }
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int minres = INT_MAX;
        int m = heights.size(), n = heights[0].size();
        vector<int> unseen(m * n, 0);
        dfs(heights, 0, 0, 0, minres, unseen);
        return minres;
    }
};
*/