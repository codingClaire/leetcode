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