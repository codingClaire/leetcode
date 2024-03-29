/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [](const auto &u, const auto &v)
             { return u[0] < v[0]; });
        int n = intervals.size();
        vector<int> f(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (intervals[j][1] <= intervals[i][0])
                    f[i] = max(f[i], f[j] + 1);
            }
        }
        return n - *max_element(f.begin(), f.end());
    }
};
// @lc code=end
