class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        if (k == 0)
            return nums;
        int vsize = nums.size();
        vector<int> res(vsize, -1);
        if (nums.size() < 2 * k + 1)
            return res;
        vector<long int> mp(vsize - k + 1);
        for (int j = 0; j < k; j++)
            mp[0] += nums[j];
        for (int i = 1; i <= vsize - k; i++)
        {
            mp[i] = mp[i - 1] - nums[i - 1] + nums[i + k - 1];
        }
        for (int i = k; i < vsize - k; i++)
        {
            long int aver = mp[i - k] + nums[i] + mp[i + 1];
            aver = floor(aver / (2 * k + 1));
            res[i] = int(aver);
        }
        return res;
    }
};