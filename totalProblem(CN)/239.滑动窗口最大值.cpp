/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
//[239] 滑动窗口最大值
// 方法一：优先队列 27.19 % 19.65 %
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        //根据优先级维护顺序 （堆）
        vector<int> res;
        priority_queue<pair<int, int>> q;
        //放入前k个
        for (int i = 0; i < k; i++)
        {
            q.emplace(nums[i], i);
        }
        //前k个的最大值
        res.emplace_back(q.top().first);
        for (int i = k; i < nums.size(); i++)
        {
            //往下放1个
            q.emplace(nums[i], i);
            // 删除1个
            while (q.top().second <= i - k)
                q.pop();
            //堆顶的元素就是堆中所有元素的最大值
            res.emplace_back(q.top().first);
        }
        return res;
    }
};
// @lc code=end
//方法二：单调队列 76.36% 36.36%
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        // s存储了还没被移除的下标
        deque<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!s.empty() && nums[s.back()] <= nums[i])
            {
                s.pop_back();
            }
            s.push_back(i);
            if (s.front() == i - k)
            {
                s.pop_front();
            }
            if (i + 1 >= k)
            {
                res.push_back(nums[s.front()]);
            }
        }
        return res;
    }
};