class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        long long res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int minV = nums[i], maxV = nums[i];
            for (int j = i; j < nums.size(); j++)
            {
                minV = fmin(nums[j], minV);
                maxV = fmax(nums[j], maxV);
                res += (maxV - minV);
            }
        }
        return res;
    }
};