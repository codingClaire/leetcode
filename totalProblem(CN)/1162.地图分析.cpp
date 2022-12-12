/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 */

// @lc code=start
//多源最短路修改后的dijkstra+bfs 17.87 %  38.72 % 
class Solution
{
public:
    static constexpr int MAX_N = 100 + 5;
    static constexpr int INF = int(1E6);
    static constexpr int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int n;
    int d[MAX_N][MAX_N];

    struct Status
    {
        int v, x, y;
        bool operator<(const Status &rhs) const
        {
            return v > rhs.v;
        }
    };

    priority_queue<Status> q; //用优先队列

    int maxDistance(vector<vector<int>> &grid)
    {
        this->n = grid.size();
        auto &a = grid;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                d[i][j] = INF;
            }
        }
        // 把陆地作为超级点集
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (a[i][j])
                {
                    d[i][j] = 0;
                    q.push({0, i, j});
                }
            }
        }

        while (!q.empty())
        {
            auto f = q.top();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nx = f.x + dx[i], ny = f.y + dy[i];
                if (!(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= n - 1))
                {
                    continue;
                }
                if (f.v + 1 < d[nx][ny])
                {
                    d[nx][ny] = f.v + 1;
                    q.push({d[nx][ny], nx, ny});
                }
            }
        }

        int ans = -1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!a[i][j])
                {
                    ans = max(ans, d[i][j]);
                }
            }
        }

        return (ans == INF) ? -1 : ans;
    }
};
// @lc code=end
// 会TLE...
class Solution
{
public:
    vector<vector<int>> direction = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isvisited[100 + 5][100 + 5];
    struct Coordinate
    {
        int x, y, step;
    };

    int getMinDis(int i, int j, vector<vector<int>> &grid, int m, int n)
    {
        // 每次isvisited都要重新更新
        memset(isvisited, 0, sizeof isvisited);
        // cout<<"getMindis:"<<i<<" "<<j<<endl;
        queue<Coordinate> q;
        q.push({i, j, 0});
        isvisited[i][j] = 1;
        while (!q.empty())
        {
            auto f = q.front();
            q.pop();
            for (int d = 0; d < 4; d++)
            {
                int curi = f.x + direction[d][0], curj = f.y + direction[d][1];
                if (!(curi >= 0 && curi < m && curj >= 0 && curj < n))
                    continue;
                if (!isvisited[curi][curj])
                {
                    q.push({curi, curj, f.step + 1});
                    isvisited[curi][curj] = 1;
                    // 找到1就直接返回
                    if (grid[curi][curj] == 1)
                        return f.step + 1;
                }
            }
        }
        return -1;
    }

    int maxDistance(vector<vector<int>> &grid)
    {
        int res = -1;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int dis = getMinDis(i, j, grid, m, n);
                    res = max(dis, res);
                }
            }
        }
        return res;
    }
};