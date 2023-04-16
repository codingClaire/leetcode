/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution 
{
public:
    void dfs(vector<vector<int>>& res, vector<int>& tmp, 
            vector<int>& nums, int index, bool choose)
    {
        if(index == nums.size())
        {
            res.emplace_back(tmp);
            return;
        }
        dfs(res, tmp, nums, index+1, false);
        if(!choose && index>0 && nums[index-1] == nums[index])
            return;
        tmp.emplace_back(nums[index]);
        dfs(res, tmp, nums, index+1, true);
        tmp.pop_back(); 
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>>  res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(res, tmp,nums,0, false);
        return res;
    }
};
// @lc code=end

