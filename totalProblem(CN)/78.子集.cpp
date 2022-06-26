/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
// [78] 子集
// 100 %  99.7 %
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> tmp;
        for (int i = 0; i < (1 << n); i++) // i: [0,2^n)
        {
            for(int j=0;j<n;j++)
            {
                if ( i & (1 << j))
                    tmp.emplace_back(nums[j]);
            }
            res.emplace_back(tmp);
            tmp.clear();
        }
        return res;
    }
};
// @lc code=end
// [78] 子集
// 43.3 % 15.1 %
class Solution
{
public:
    void backtrack(vector<vector<int>> &res, vector<int> tmp, 
                    vector<int> nums, int index)
    {
        res.emplace_back(tmp);
        for (int i = index; i < nums.size(); i++)
        {
            tmp.push_back(nums[i]);
            backtrack(res, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res, tmp, nums, 0);
        return res;
    }
};