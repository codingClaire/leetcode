/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
// [46] 全排列
class Solution {
public:
    void backtrack(vector<vector<int>> &res,
                   vector<int> &tmp, vector<int> &nums,int index)
    {
        if(index == nums.size())
        {
            res.emplace_back(tmp);
        }
        else
        {
            for (int i = index; i <nums.size(); i++)
            {
                swap(tmp[i],tmp[index]);
                backtrack(res,tmp,nums,index+1);
                swap(tmp[i], tmp[index]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res,nums,nums,0);
        return res;
    }
};
// @lc code=end

