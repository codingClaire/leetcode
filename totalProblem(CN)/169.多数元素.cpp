/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
// [169] 多数元素
//投票算法
/*
Boyer-Moore 投票算法：
重点介绍这个算法，主要就是维护两个数组，一个是 count 数组，另一个是 value 数组。
count 数组的计算是这样的：
如果当前 index 的 count 数组值为零，那么当前 index 的数就会是当前的 candidate，
count 表示的是当前 candidate 出现的次数比非 candidate 出现的次数多几次，
这样在遍历数组计算 count 时，遇到和当前 candidate 相同的数就加 1，否则就减 1。
在最后一段中，candidate 存储的候选众数就是真正的众数。
（为什么？可以理解乘众数和非众数两个阵营以一敌一地厮杀，
直到最后剩下的必然属于多数阵营，所以最后存储的就是多数阵营）
*/
// 70.56% 34.53%
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = -1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == candidate)
            {
                count++;
            }
            else if (--count < 0)
            { // count减1后，如果小于0
                candidate = nums[i];
                count = 1;
            }
        }
        return candidate;
    }
};
// @lc code=end
//分治法
// 37.80% 5.37%
class Solution
{
    int countNum(vector<int> &nums, int target, int l, int r)
    {
        int count = 0;
        for (int i = l; i <= r; i++)
        {
            if (nums[i] == target)
                count++;
        }
        return count;
    }
    int backtrack(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return nums[l];
        int mid = (l + r) / 2;
        int left_num = backtrack(nums, l, mid);
        int right_num = backtrack(nums, mid + 1, r);
        if (countNum(nums, left_num, l, r) > (r - l + 1) / 2)
            return left_num;
        if (countNum(nums, right_num, l, r) > (r - l + 1) / 2)
            return right_num;
        return -1;
    }

public:
    int majorityElement(vector<int> &nums)
    {
        return backtrack(nums, 0, nums.size() - 1);
    }
};
//排序法
// 15% 45%
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};