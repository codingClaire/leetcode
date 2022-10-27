    /*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

    // @lc code=start
    //[75] 颜色分类
    // 双指针 40.59 % 87.23 %
    //方法二：只维护一个头部，始终有连续的 0 和连续的 1。
    class Solution
    {
    public:
        void sortColors(vector<int> &nums)
        {
            //用两个指针分别指示最后一个 0 和 1 的下一个位置
            int zero = 0, one = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                { //如果找到 0，那么就和 zero 指针交换，
                    swap(nums[zero], nums[i]);
                    //但是这样会把一个 已经排好的1 换出去，所以就再把它换到 1 的最后即可
                    if (zero < one)
                    {
                        swap(nums[i], nums[one]);
                    }
                    //都更新
                    zero++;
                    one++;
                }
                else if (nums[i] == 1)
                { //如果找到 1，那么就和 one 指针交换，并后移，
                    swap(nums[one], nums[i]);
                    one++;
                }
            }
        }
};
// @lc code=end
// 40.59 % 71.91 %
//方法一：先把 0 交换到最前，再把 1 交换到最前。（这样需要两次遍历）
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int head = 0;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == 0)
            {
                swap(nums[head], nums[i]);
                head++;
            }
            i++;
        }
        int j = head;
        while (j < nums.size() && head < nums.size())
        {
            if (nums[j] == 1)
            {
                swap(nums[head], nums[j]);
                head++;
            }
            j++;
        }
    }
};

//二刷
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int zero = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[zero]);
                zero++;
            }
        }
        int one = zero;
        for (int i = zero; i < nums.size(); i++)
        { //从相等的开始，因为即使当前是1，自己和自己交换，one指针也在前进
            if (nums[i] == 1)
            {
                swap(nums[i], nums[one]);
                one++;
            }
        }
    }
};