/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start

// @lc code=end
// 二分查找 O(nlogn) 40.25 % 58.51 %
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // cnt数组随着数字i逐渐增大而具有单调性
        int n = nums.size();
        int left = 1, right = n - 1, ans = -1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            int cnt = 0; // cnt存储数组小于mid的数量
            for (int i = 0; i < n; i++)
                cnt += (nums[i] <= mid);

            if (cnt <= mid)
            { //说明重复的数在右侧
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
                // 为什么要在这里更新？
                //因为这里是cnt>mid的目前找到的最小的一个
                //二分查找就逐渐往右 找到cnt>mid的最小的一个
                ans = mid;
            }
        }
        return ans;
    }
};

// 快慢指针法 O(n)：78.31 %  24.18 %
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // 等价于找环的入口，重复数相当于环的入口
        // 假设起始到入口点为a，相遇的地方将环分为b和c两段
        // 此时快慢指针相遇，快比慢多走了n圈
        // 这时就有等量关系 2(a+b) = a+(n+1)b+nc
        // 整理得： a = c +(n-1)(b+c)
        // 因此这时候再设置一个指针ptr指向起始点，和slow一起走
        // 当指针ptr走a时，slow走c +(n-1)(b+c)
        // 由于b+c就是一整圈，第一阶段时slow在走过b的点
        // 那么显然刚好就在环的起始点相遇
        int slow = 0, fast = 0;
        // 第一阶段
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        // 第二阶段
        slow = 0; //相当于ptr，指向起始点
        while (slow != fast)
        {
            slow = nums[slow]; 
            fast = nums[fast]; // 充当之前的slow
        }
        return slow;
    }
};