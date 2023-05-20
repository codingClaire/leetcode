/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<int>> &ans, vector<int> &tmp, vector<int> &candidates, int target, int idx)
    {
        if (target == 0)
        {
            ans.emplace_back(tmp);
            return;
        }
        for (int i = idx; i < candidates.size() && target - candidates[i] >= 0; i++)
        {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            tmp.emplace_back(candidates[i]);
            dfs(ans, tmp, candidates, target - candidates[i], i + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(ans, tmp, candidates, target, 0);
        return ans;
    }
};
// @lc code=end

// 以下的解法是没办法正确的
class Solution
{
public:
    void dfs(vector<vector<int>> &ans, vector<int> &tmp, vector<int> &candidates, int target, int idx)
    {
        if (idx == candidates.size())
            return;
        if (target == 0)
        {
            ans.emplace_back(tmp);
            return;
        }
        dfs(ans, tmp, candidates, target, idx + 1);
        //为什么呢？ 因为没办法确定前面是否选择了candidate[idx]
        // 这样实际上就会导致漏掉一些结果！！ 
        if (target - candidates[idx] >= 0 && candidates[idx] != candidates[idx + 1])
        {
            tmp.emplace_back(candidates[idx]);
            dfs(ans, tmp, candidates, target - candidates[idx], idx + 1);
            tmp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(ans, tmp, candidates, target, 0);
        return ans;
    }
};

// 在示例里 第一个组合不会出现（[ 1, 1, 6 ]）
// [[ 1, 1, 6 ], [ 1, 2, 5 ], [ 1, 7 ], [ 2, 6 ] ]