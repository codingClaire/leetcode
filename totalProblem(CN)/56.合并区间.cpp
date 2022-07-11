/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
//[56] 合并区间
// 11.15 % 79.15 %
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        res.emplace_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=res.back()[1])
                res.back()[1] = max(intervals[i][1],res.back()[1]);
            else
                res.emplace_back(intervals[i]);
        }
        return res;
    }
};
// @lc code=end
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    { // bigger first (useless)
        if (a[0] > b[0])
            return b < a;
        else if (a[0] < b[0])
            return b > a;
        else
        {
            if (a[1] > b[1])
                return b < a;
            return b > a;
        }
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp) return intervals;
    }
};
