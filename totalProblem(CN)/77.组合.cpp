/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
// 组合枚举
class Solution
{
public:
    vector<int> temp;
    vector<vector<int>> ans;
    
    void dfs(int cur, int n, int k)
    {
        // 机智的剪枝：temp 长度加上区间 [cur, n] 的长度小于 k
        // 不可能构造出长度为 k 的 temp
        // 因为区间里的已经不够选了
        if (temp.size() + (n - cur + 1) < k)
        {
            return;
        }
        // 记录合法的答案
        if (temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        // dfs是不断地缩小cur到n
        // 考虑选择当前位置
        temp.push_back(cur);
        dfs(cur + 1, n, k);
        temp.pop_back();
        // 考虑不选择当前位置
        dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k)
    {
        dfs(1, n, k);
        return ans;
    }
};

// @lc code=end

class Solution
{
public:
    void recurAns(int l, int r, int k, vector<int> &path, vector<vector<int>> &ans)
    {
        if (path.size() == k)
        {
            ans.push_back(path);
            return;
        }
        if (l > r)
            return;
        recurAns(l + 1, r, k, path, ans);
        path.push_back(l);
        recurAns(l + 1, r, k, path, ans);
        path.pop_back();
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> path;
        recurAns(1, n, k, path, ans);
        return ans;
    }
};