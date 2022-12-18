/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
// 57.27 %   34.27 %
class Solution
{
public:
    unordered_map<string, 
                priority_queue<string, vector<string>, std::greater<string>>> 
                vec;
    vector<string> stk;//栈
    void dfs(const string& curr)
    {
        // 最多存在一个死胡同(出度和入度相差1） 所以只需要保证死胡同最先入栈就可以
        while(vec.count(curr) && vec[curr].size()>0)
        {
            string tmp = vec[curr].top();
            vec[curr].pop();
            dfs(move(tmp)); // move是一个优化，可以减小内存
        }
        // 先加入没有出度的点 
        // 当遍历完一个节点所连的所有节点后，我们才将该节点入栈（即逆序入栈）
        stk.emplace_back(curr);
    }
    
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for(auto& it: tickets)
        {
            vec[it[0]].emplace(it[1]);
        }
        dfs("JFK");

        reverse(stk.begin(),stk.end());
        return stk;
    }
};
// @lc code=end
