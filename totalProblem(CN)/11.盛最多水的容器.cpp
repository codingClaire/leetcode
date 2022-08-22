/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
// 96.16 % 93.71 %
class Solution
{
public:
    int solveArea(int left, int right, int interval)
    {
        return min(left, right) * interval;
    }

    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int right = n - 1, left = 0;
        int res = solveArea(height[right], height[left], 1);
        while (left < right)
        {
            int area = solveArea(height[right], height[left], right - left);
            res = max(res, area);
            if (height[left] > height[right])
                right--;
            else
                left++;
        }
        return res;
    }
};
// @lc code=end
//[4,3,2,1,4]

//错误的尝试！！！虽然也想到了双指针，但是根本没写好
class Solution
{
public:
    int solveArea(int left, int right, int interval)
    {
        return min(left, right) * interval;
    }

    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int right = n / 2, left = n / 2 - 1;
        int res = solveArea(height[right], height[left], 1);
        while (right <= n - 2 || left >= 1)
        {
            cout << left << " " << right << " " << res << endl;
            int l = left, r = right;
            if (l < 1)
            {
                l = 1;
                right++;
            }
            if (r > n - 2)
            {
                r = n - 2;
                left--;
            }
            int rightmore = solveArea(height[l], height[r + 1], r + 1 - l);
            int leftmore = solveArea(height[l - 1], height[r], r - l + 1);
            if (rightmore > leftmore)
            {
                res = max(res, rightmore);
                right++;
            }
            else
            {
                res = max(res, leftmore);
                left--;
            }
        }
        return res;
    }
};