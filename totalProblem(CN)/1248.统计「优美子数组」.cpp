/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 *
 * [1248] 统计「优美子数组」
 */

// @lc code=start
// 86.22% 46.95%
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        // 频次数组 cnt 记录 pre[i] 出现的次数
        vector<int> cnt(n + 1, 0);
        vector<int> pre(n + 1, 0);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            // 记得这个&1要加括号
            pre[i + 1] = pre[i] + (nums[i] & 1);
        }
        for (int i = 0; i < n + 1; i++)
        {
            if (pre[i] - k >= 0)
            {
                res += cnt[pre[i] - k];
            }
            // 前缀和的值增加计数
            cnt[pre[i]]++;
        }
        return res;
    }
};
// @lc code=end
// 优化后 94.71 %  67.14 %
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        // 频次数组 cnt 记录 pre[i] 出现的次数
        vector<int> cnt(n + 1, 0);
        int odd = 0, res = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; i++)
        {
            odd += nums[i] & 1;
            // 转化为和为k的子数组（奇数是1，偶数是0）
            res += odd >= k ? cnt[odd - k] : 0;
            cnt[odd]++;
        }
        return res;
    }
};