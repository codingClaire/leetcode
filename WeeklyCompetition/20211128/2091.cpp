class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        int totalnum = 0;
        int minIndex = 0, maxIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < nums[minIndex])
                minIndex = i;
            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }
        vector<int> candidate;
        if (minIndex == maxIndex)
        {
            //only one element
            return 1;
        }
        else if (minIndex < maxIndex)
        {
            candidate = {
                int(minIndex + 1 + nums.size() - maxIndex),
                int(maxIndex + 1),
                int(nums.size() - minIndex)};
        }
        else
        {
            candidate = {
                int(maxIndex + 1 + nums.size() - minIndex),
                int(minIndex + 1),
                int(nums.size() - maxIndex)};
        }
        auto minTotalIndex = min_element(candidate.begin(), candidate.end());
        return *minTotalIndex;
    }
};