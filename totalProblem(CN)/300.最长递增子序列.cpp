/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
//[300] 最长递增子序列
// 49.78 % 36.73 %
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
// @lc code=end
//贪心+二分法
//上升子序列尽可能长->序列上升得尽可能慢->每次在上升子序列最后加上的数尽可能小
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> d(n, 0);
        // d[i]表示长度为i+1的子序列的最小的元素
        int len = 0;
        d[len] = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > d[len])
                d[++len] = nums[i];
            else
            {
                int l = 0, r = len, pos = -1; // 注意这里pos要设置为-1
                //如果范围内的数都等于或比nums[i]小，那么就把nums[i]更新至d[0]中
                //[l,r)的二分查找,pos存储的是d里第一个比nums[i]大的数
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i])
                    {
                        pos = mid;
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len + 1;
    }
};
// inspired by 2111 answer
/* 注意：这个题解无法通过一个upper_bound函数实现，如这一个例子[4,10,4,3,8,9]
使用上面的题解中
d=[4]
i=1 d=[4,10]
i=2 d=[4,10] （在[4,10)区间，无法找到比nums[2]=4更大的d，因此pos=-1）
i=3 d=[3,10]
i=4 d=[3,8] （在[3,10)区间，pos=0，尽管无法找到比nums[4]=8更大的d，但仍然pos得到了更新）
i=5 d=[3,8,9]

但是如果用upper_bound的函数，[3,10)区间是找不到比nums[4]更大的d，所以无法区分i=2和i=4的两种情况，因此还是不要用）
*/
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> d(n, 0);
        // d[i]表示长度为i+1的子序列的最小的元素
        int len = 0;
        d[len] = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > d[len])
                d[++len] = nums[i];
            else
            {
                auto it = upper_bound(d.begin(), d.begin() + len, nums[i]);
                if (it != d.begin() + len)
                    *(it) = nums[i];
                else
                    d[0] = nums[i];
            }
        }
        return len + 1;
    }
};