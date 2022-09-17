/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
// 广度优先遍历  87.02 % 63.06 %
class Solution
{
public:
    vector<vector<int>> edges;
    vector<int> indeg;
    vector<int> result; // 拓扑排序结果

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        //更新每个节点的出边，即每个节点访问前需要先访问的节点
        for (const auto &pre : prerequisites)
        {
            edges[pre[1]].emplace_back(pre[0]);
            indeg[pre[0]]++; // 统计节点的入边数
        }
        queue<int> q;
        // 先放入不需要先修课程的节点，也就是入度为0的节点
        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
                q.push(i);
        }
        int visited = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            result.emplace_back(u);
            for (int v : edges[u])
            {
                indeg[v]--;
                // 能加入队列的条件是先修课程都修完了，也就是入边减到0了
                if (indeg[v] == 0)
                    q.push(v);
            }
        }
        if(result.size() == numCourses)
            return result;
        else 
            return {};
    }
};
// @lc code=end
// 深度优先遍历  18.37 % 48.66 %
class Solution
{
public:
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> result; // 拓扑排序结果
    bool valid = true;
    void DFS(int u)
    {
        // 状态：0-未访问 1-正在访问 2-结束访问
        // 1. 当前节点标记为正在访问
        visited[u] = 1;
        // 2. 递归遍历其他节点
        for (int v : edges[u])
        {
            // 正常情况，遇到的其他节点的状态都应该是0或2
            //如果是2，就说明后面的课程已经上完了，已经回溯回来了，这时候不需要任何操作
            //如果是0，那么就继续DFS，不断地递归，这个过程中没上完的课都会是一个正在访问的状态
            if (visited[v] == 0)
            {
                DFS(v);
                if (!valid)
                    return;
            }
            //有向无环图中，不应该遇到正在访问的其他节点
            // 如果遇到了，说明出现了环，更新valid并返回
            else if (visited[v] == 1)
            {
                valid = false;
                return;
            }
        }
        // 3. u标记为结束访问状态
        visited[u] = 2;
        result.emplace_back(u);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto &pre : prerequisites)
        {
            edges[pre[1]].emplace_back(pre[0]);
        }
        for (int i = 0; i < numCourses && valid; i++)
        {
            if (!visited[i])
                DFS(i);
        }
        if (!valid)
            return {};
        reverse(result.begin(), result.end());
        return result;
    }
};