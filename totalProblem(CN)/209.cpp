// 官方题解1
// 前缀和+二分查找
// 时间复杂度O(nlogn)，空间复杂度O(n)

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        int ans = INT_MAX;
        vector<int> sums(len + 1, 0); //创建前缀和数组
        for (int i = 1; i <= len; i++)
        {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < len; i++)
        {
            int t = target + sums[i];
            auto bound = lower_bound(sums.begin(), sums.end(), t); 
            // bound说明当前元素的前缀和包含了target和前i个元素的和，如果bound存在
            // 那么ans就可以用bound的index减去i，表示这个区间（从第i个到当前元素）的和大于等于target
            if (bound != sums.end())
            {
                ans = fmin(ans, static_cast<int>((bound - sums.begin()) - i));
            }
        }
        if (ans == INT_MAX)
            return 0;
        return ans;
    }
};

// 官方题解2
// 滑动窗口
// 时间复杂度O(n), 空间复杂度O(1)
// 两个指针都指向下标0，每一轮都迭代将末尾加到sum，如果满足大于等于target，那么记录子数组的长度
// 然后将start右移一位，重复上述操作

// 自己写的版本
// 执行用时：8 ms, 在所有 C++ 提交中击败了 75.17 % 的用户 内存消耗： 10.3 MB, 在所有 C++ 提交中击败了 54.78 % 的用户 

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        int ans = len + 1;
        int start = 0, end = -1;
        int sum = 0;
        while (start != len)
        {
            while (sum < target && end < len - 1)
            {
                end++;
                sum += nums[end];
            }
            if (sum >= target)
                ans = fmin(ans, end - start + 1);
            sum = sum - nums[start];
            start++;
        }
        if (ans == len + 1)
            return 0;
        return ans;
    }
};

// 题解版本
// 题解版本的区别是会多次移动start指针，直到sum小于target
// 两个排名相似 
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while (end < n)
        {
            sum += nums[end];
            while (sum >= s)
            {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};