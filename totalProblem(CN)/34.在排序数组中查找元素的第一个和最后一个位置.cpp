/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
//[34] 在排序数组中查找元素的第一个和最后一个位置
// 92.64 % 16.44 %
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int min_pos=nums.size(),max_pos = nums.size(); // 非常重要的初始化
        //如果比target更大的数不存在，那么max_pos会在最后成为nums.size()-1
        // [1] 1那个样例就能够通过
        // find min pos
        int left = 0, right = nums.size() - 1, mid = -1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if(nums[mid]>=target)
            {
                right = mid-1;
                min_pos = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        // find max pos
        left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left+right)/2;
            //left + (right - left) / 2;
            if (nums[mid] > target)
            {
                right = mid-1;
                max_pos = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        max_pos--;
        if(min_pos<=max_pos&&max_pos<nums.size()&&nums[min_pos]==target&&nums[max_pos]==target)
        //很重要的判断！！
            return vector<int>{min_pos,max_pos};
        return vector<int>{-1,-1};
    }
};
// @lc code=end
#include <bits/stdc++.h>
using namespace std;
class Solution1
{ //二分查找
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size() - 1;
        vector<int> res;
        if (n == -1)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int L = 0, R = nums.size() + 1;
        int left = 0, right = 0;
        while (L < R)
        { //找最右边的标号
            int mid = (L + R) / 2;
            if (mid <= n && nums[mid] <= target)
            {
                right = mid;
                L = mid + 1;
            }
            else
                R = mid;
        }
        L = 0;
        R = nums.size();
        while (L < R)
        { //找最左边的标号
            int mid = (L + R) / 2;
            if (mid <= n && nums[mid] >= target)
            {
                left = mid;
                R = mid;
            }
            else
                L = mid + 1;
        }
        if (nums[right] == target)
        {
            res.push_back(left);
            res.push_back(right);
        }
        else
        {
            res.push_back(-1);
            res.push_back(-1);
        }

        return res;
    }
};

class Solution2
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans = {-1, -1};
        auto l = lower_bound(nums.begin(), nums.end(), target);
        int leftidx = distance(nums.begin(), l);
        if (l != nums.end() && nums[leftidx] == target)
            ans[0] = leftidx;
        auto r = upper_bound(nums.begin(), nums.end(), target);
        int rightidx = distance(nums.begin(), r) - 1; //不可以写成r-1,-1操作要在distance外面
        if (r != nums.begin() && nums[rightidx] == target)
            ans[1] = rightidx;
        return ans;
    }
};

int main()
{
    Solution2 A;
    vector<int> nums{2, 2};
    int target = 3;
    vector<int> res;
    res = A.searchRange(nums, target);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}