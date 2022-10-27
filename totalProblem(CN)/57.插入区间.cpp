/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
// 96.71% 35.72%
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int n = intervals.size();
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        for (int i = 0; i < n; i++)
        {
            if (intervals[i][0] > right)
            { //当前集合左侧大于插入集合右侧
                if (!placed)
                { // 没有插入的情况，就把它放进去
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.emplace_back(intervals[i]);
            }
            else if (intervals[i][1] < left)
            { //当前集合右侧小于插入集合左侧
                ans.emplace_back(intervals[i]);
            }
            else
            {
                left = min(left, intervals[i][0]);
                right = max(right, intervals[i][1]);
            }
        }
        // 如果这时候还没有被放进去
        if (!placed)
        {
            ans.push_back({left, right});
        }
        return ans;
    }
};
// @lc code=end
