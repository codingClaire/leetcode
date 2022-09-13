/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
//求最大连通分量个数
// 并查集 15.16 % 46.66 %
class Solution
{
public:
    int Find(vector<int>& parent,int index)
    {
        //向上递归查找
        if(parent[index]!=index)
            parent[index] = Find(parent,parent[index]);
        //返回最深的祖先
        return parent[index];
    }

    void Union(vector<int>& parent, int index1, int index2)
    {
        //合并祖先
        parent[Find(parent,index1)] = Find(parent,index2);
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int nodes = isConnected.size();
        vector<int> parent(nodes);
        int provinces = 0;
        for(int i=0;i<nodes;i++)
            parent[i] = i;
        for(int i=0;i<nodes;i++)
        {
            for(int j=i+1;j<nodes;j++)
            {
                if(isConnected[i][j]==1)
                    Union(parent,i,j);
            }
        }
        for(int i=0;i<nodes;i++)
        {
            if(parent[i]==i)
                provinces++;
        }
        return provinces;
    }
};
// @lc code=end
// BFS 9.95 %  18.16 %
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int nodes = isConnected.size();
        vector<int> isVisited(nodes);
        int provinces = 0;
        queue<int> q;
        //从i开始作为起点，每个没被访问过的都进行一次BFS搜索
        for (int i = 0; i < nodes; i++)
        {
            if (!isVisited[i])
            {
                // BFS模板
                q.push(i);
                while (!q.empty())
                {
                    int j = q.front();
                    q.pop();
                    // 更新访问的数组
                    isVisited[j] = 1;
                    //将当前的所有与之相连的节点加入队列
                    for (int k = 0; k < nodes; k++)
                    {
                        if (isConnected[j][k] == 1 && !isVisited[k])
                            q.push(k);
                    }
                }
                provinces++;
            }
        }
        return provinces;
    }
};

//求最大连通分量个数
// DFS 92.37 % 42.28 %
class Solution
{
public:
    void DFS(vector<vector<int>> &isConnected, vector<int> &isVisited, int nodes, int startnode)
    {
        for (int i = 0; i < nodes; i++)
        {
            if (isConnected[startnode][i] == 1 && !isVisited[i])
            {
                isVisited[i] = 1;
                DFS(isConnected, isVisited, nodes, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int nodes = isConnected.size();
        vector<int> isVisited(nodes);
        int provinces = 0;
        for (int i = 0; i < nodes; i++)
        {
            if (!isVisited[i])
            {
                DFS(isConnected, isVisited, nodes, i);
                provinces++;
            }
        }
        return provinces;
    }
};