/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
//[215] 数组中的第K个最大元素
// 96.59 % 5.03 %
class Solution
{
public:
    int quicksort(vector<int> v, int left, int right, int k)
    {
        cout << left << " " << right << " " << k << endl;
        int picked = rand() % (right - left + 1) + left;
        swap(v[picked], v[left]);
        int pivot = v[left];
        int index = left;
        // 找到所有大于该元素的值
        for (int i = left + 1; i <= right; i++)
        {
            if (v[i] >= pivot)
            {
                swap(v[index + 1], v[i]);
                index++;
            }
        }
        swap(v[left], v[index]);
        if (index - left + 1 > k)
        {
            return quicksort(v, left, index - 1, k);
        }
        else if (index - left + 1 == k)
        {
            return v[index];
        }
        else // (k > index - left + 1)
        {
            return quicksort(v, index + 1, right, k - (index - left + 1));
        }
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        int res = quicksort(nums, 0, nums.size() - 1, k);
        return res;
    }
};
// TODO: 小顶堆复习待做
// @lc code=end
