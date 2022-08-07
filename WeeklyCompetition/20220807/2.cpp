class Solution
{
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        unordered_set<int> st;
        int rsize = restricted.size();
        for (int i = 0; i < rsize; i++)
        {
            st.insert(restricted[i]);
        }
        vector<int> preserve_edges;
        int esize = edges.size();
        for (int i = 0; i < esize; i++)
        {
            if (!st.count(edges[i][0]) && !st.count(edges[i][1]))
            {
                preserve_edges.emplace_back(i);
            }
        }
        unordered_set<int> node_set;
        node_set.insert(0);
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int num = q.front();
            q.pop();
            vector<int> del;
            for (int i = 0; i < preserve_edges.size(); i++)
            {
                int index = preserve_edges[i];
                if (edges[index][0] == num)
                {
                    q.push(edges[index][1]);
                    node_set.insert(edges[index][1]);
                    del.emplace_back(i);
                }
                else if (edges[index][1] == num)
                {
                    q.push(edges[index][0]);
                    node_set.insert(edges[index][0]);
                    del.emplace_back(i);
                }
            }
            for (int i = del.size() - 1; i >= 0; i--)
            {
                preserve_edges.erase(preserve_edges.begin() + del[i]);
            }
        }
        return node_set.size();
    }
};
/*
7
[[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]]
[4,5]
7
[[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]]
[4,2,1]
10
[[8,2],[2,5],[5,0],[2,7],[1,7],[3,8],[0,4],[3,9],[1,6]]
[9,8,4,5,3,1]

*/