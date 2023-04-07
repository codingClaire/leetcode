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
//逐行注释版
class Solution
{
public:
    // 定义一个quicksort函数，接受一个vector<int> v，左右端点left和right，和k作为参数
    int quicksort(vector<int> v, int left, int right, int k)
    {
        // 输出左右端点和k的值
        cout << left << " " << right << " " << k << endl;
        // 随机选择一个位置picked
        int picked = rand() % (right - left + 1) + left;
        // 将该位置的值和left位置的值交换
        swap(v[picked], v[left]);
        // 将left位置的值作为pivot
        int pivot = v[left];
        // 将index初始化为left
        int index = left;
        // 找到所有大于等于pivot的值，并将它们移到左侧
        for (int i = left + 1; i <= right; i++)
        {
            if (v[i] >= pivot)
            {
                swap(v[index + 1], v[i]);
                index++;
            }
        }
        // 将pivot移到正确的位置
        swap(v[left], v[index]);
        // 如果pivot左侧的元素数量大于k，递归在左侧继续查找
        if (index - left + 1 > k)
        {
            return quicksort(v, left, index - 1, k);
        }
        // 如果pivot左侧的元素数量等于k，返回pivot
        else if (index - left + 1 == k)
        {
            return v[index];
        }
        // 如果pivot左侧的元素数量小于k，递归在右侧继续查找
        else // (k > index - left + 1)
        {
            return quicksort(v, index + 1, right, k - (index - left + 1));
        }
    }
    // 定义一个findKthLargest函数，接受一个vector<int> nums和一个整数k作为参数
    int findKthLargest(vector<int> &nums, int k)
    {
        // 调用quicksort函数，并返回结果
        int res = quicksort(nums, 0, nums.size() - 1, k);
        return res;
    }
};