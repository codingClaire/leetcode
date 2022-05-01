/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// [278] 第一个错误的版本
// 100 %  49.4 %
class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 0, right = n;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // noway: int mid = (left + right) / 2;
            if (isBadVersion(mid) == false)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return right;
    }
};
// @lc code=end
