class Solution
{
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
            {
                R = mid;
            }
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
            {
                L = mid + 1;
            }
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