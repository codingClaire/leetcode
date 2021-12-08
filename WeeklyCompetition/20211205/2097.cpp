//一个TLE的解法：暴力，基本思路是先找到起始和终止的数对，然后再一个个匹配
class Solution
{
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        vector<vector<int>> res;
        vector<int> front;
        vector<int> last;
        for (auto iter1 = pairs.begin(); iter1 != pairs.end(); iter1++)
        {
            bool fflag = false, lflag = false;
            vector<int> tmp1 = *iter1;
            for (auto iter2 = pairs.begin(); iter2 != pairs.end(); iter2++)
            {
                vector<int> tmp2 = *iter2;
                if (iter1 != iter2 && tmp1[0] == tmp2[1])
                    fflag = true; // have front vector
                if (iter1 != iter2 && tmp1[1] == tmp2[0])
                    lflag = true; // have last vector
            }
            if (fflag == false)
            {
                front.emplace_back(tmp1[0]);
                front.emplace_back(tmp1[1]);
                pairs.erase(iter1);
            }
            if (lflag == false)
            {
                last.emplace_back(tmp1[0]);
                last.emplace_back(tmp1[1]);
                pairs.erase(iter1);
            }
        }
        res.emplace_back(front);
        //auto iter3=pairs.begin();
        while (!pairs.empty())
        {
            for (auto iter3 = pairs.begin(); iter3 != pairs.end(); iter3++)
            {
                vector<int> tmp3 = *iter3;
                if (tmp3[0] == front[1])
                {
                    res.emplace_back(tmp3);
                    pairs.erase(iter3);
                    break;
                }
            }
        }
        res.emplace_back(last);
        return res;
    }
};

//官方题解
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // 存储图
        unordered_map<int, vector<int>> edges;
        // 存储入度和出度
        unordered_map<int, int> indeg, outdeg;
        for (const auto& p: pairs) {
            int x = p[0], y = p[1];
            edges[x].push_back(y);
            ++indeg[y];
            ++outdeg[x];
        }
        
        // 寻找起始节点
        int start = pairs[0][0];
        for (const auto& [x, occ]: outdeg) {
            // 如果有节点出度比入度恰好多 1，那么只有它才能是起始节点
            if (occ == indeg[x] + 1) {
                start = x;
                break;
            }
        }
        
        vector<vector<int>> ans;
        
        // 深度优先搜索（Hierholzer 算法）求解欧拉通路
        function<void(int)> dfs = [&](int u) {
            while (!edges[u].empty()) {
                int v = edges[u].back();
                edges[u].pop_back();
                dfs(v);
                ans.push_back({u, v});
            }
        };
        
        dfs(start);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};