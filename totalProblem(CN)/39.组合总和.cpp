/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
// 57.91% 23.49%
// TODO:想想剪枝操作
// 当觉得BFS不好做的时候，就应该往回溯那边去思考
class Solution
{
public:
    void DFS(vector<int> &candidates, int target,
             vector<vector<int>> &res, vector<int> &combine, int idx)
    {
        if (idx == candidates.size())
            return;
        if (target == 0)
        {
            res.emplace_back(combine);
            return;
        }
        // 选择不用，直接跳过   
        // 不选，也要有一个尽头
        DFS(candidates, target, res, combine, idx + 1);
        // 选择当前数, 并且idx不会往下更新
        if (target - candidates[idx] >= 0)
        {
            combine.emplace_back(candidates[idx]);
            DFS(candidates, target - candidates[idx], res, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> combine;
        DFS(candidates, target, res, combine, 0);
        return res;
    }
};
// @lc code=end
// 二刷
class Solution {
public:

    void dfs(vector<vector<int>>&ans , vector<int>& tmp, vector<int>& candidates, int target, int idx)
    {
        if(idx == candidates.size())
            return;
        if(target == 0)
        {
            ans.emplace_back(tmp);
            return;
        }
        // 要注意的是这里要加1
        dfs(ans, tmp, candidates,target,idx+1);
        // 这一句判断，很重要！！
        if(target-candidates[idx]>=0)
        {
            tmp.emplace_back(candidates[idx]);
            dfs(ans, tmp, candidates,target-candidates[idx],idx);
            tmp.pop_back();
        }
        return;
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>  ans;
        vector<int> tmp;
        dfs(ans, tmp, candidates, target, 0);
        return ans;
    }
};