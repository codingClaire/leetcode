/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */

// @lc code=start
//方法一 排序：  75.11 % 15.27 %
// TODO: 后续的方法看不懂哇
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        // 排序后的数组arr
        vector<int> arr = nums;
        sort(arr.begin(),arr.end());
        int x = (n+1)/2;
        // i从0到n，每次隔1个 原地更改nums
        // j从x-1到0
        // k从n-1到0
        for(int i=0,j=x-1,k=n-1;i<n;i+=2,j--,k--)
        {
            // 修改第i个
            nums[i] = arr[j];
            // 修改第i+1个
            if(i+1<n)
            {
                nums[i+1]=arr[k];
            }
        }
    }
};
// @lc code=end
