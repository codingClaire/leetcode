/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
// 71.99% 90.42%
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) -> bool
        {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
        // boundaries包含了所有的横坐标
        vector<int> boundaries;
        for (auto &building : buildings)
        {
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        //从小到大排序
        sort(boundaries.begin(), boundaries.end());
        vector<vector<int>> ret;
        int n = buildings.size(), idx = 0;
        for (auto &boundary : boundaries)
        {
            // 从0开始遍历buildings，加入左侧小于boundary的建筑物
            while (idx < n && buildings[idx][0] <= boundary)
            {
                que.emplace(buildings[idx][1], buildings[idx][2]);
                idx++;
            }
            //弹出左侧小于boundary的建筑物
            while (!que.empty() && que.top().first <= boundary)
            {
                que.pop();
            }
            // 如果queue非空的话，
            //那么当前top的最右侧就是左边界大于boundary的最小的右边界最小的值
            int maxn = que.empty() ? 0 : que.top().second;
            if (ret.size() == 0 || maxn != ret.back()[1])
                ret.push_back({boundary, maxn});
        }
        return ret;
    }
};
// @lc code=end
