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
        // 这个单调的队列，元素只从队尾进入，队头到队尾是从大到小单调的
        for (int i = 0; i < nums.size(); i++)
        {
            while (!s.empty() && nums[s.back()] <= nums[i])
            {//当前加入的比尾部的大，就消除尾部的
                s.pop_back();
            }
            //加入当前的index
            s.push_back(i);
            // 如果当前index回退k个已经到了s.front()，那么就不需要s.front()了
            if (s.front() == i - k)
            {
                s.pop_front();
            }
            //每次结果放队头的就行了
            if (i + 1 >= k)
            {
                res.push_back(nums[s.front()]);
            }
        }
        return res;
    }
};