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
        DFS(candidates, target, res, combine, idx + 1);
        // 选择当前数
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

