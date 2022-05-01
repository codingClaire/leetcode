/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
//[88] 合并两个有序数组
// 100 % 73.93 %
//逆向双指针
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
            return;
        int i = m - 1, j = n - 1;
        int cur;
        int last = m + n - 1;
        while (i >= 0 || j >= 0)
        {
            if (i == -1)
                cur = nums2[j--];
            else if (j == -1)
                cur = nums1[i--];
            else if (nums1[i] < nums2[j])
                cur = nums2[j--];
            else if (nums1[i] >= nums2[j])
                cur = nums1[i--];
            nums1[last--] = cur;
        }
    }
};
// @lc code=end

/*
[0]\n0\n[1]\n1\n
*/
//[88] 合并两个有序数组
// 44.46 % 7.08 %
//正向双指针
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
            return;
        vector<int> sorted;
        int i = 0, j = 0;
        while (i < m || j < n)
        {
            if (i == m)
                sorted.emplace_back(nums2[j++]);
            else if (j == n)
                sorted.emplace_back(nums1[i++]);
            else if (nums1[i] > nums2[j])
                sorted.emplace_back(nums2[j++]);
            else if (nums1[i] <= nums2[j])
                sorted.emplace_back(nums1[i++]);
        }
        int len = sorted.size();
        for (int idx = 0; idx < len; idx++)
        {
            nums1[idx] = sorted[idx];
        }
    }
};