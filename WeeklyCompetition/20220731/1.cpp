class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        unordered_set<int> zeroIndex;
        int operationNum = 0;
        if (accumulate(nums.begin(), nums.end(), 0) == 0)
            return operationNum;
        int n = nums.size();
        while (zeroIndex.size() != n)
        {
            int minvalue = INT_MAX;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] < minvalue && nums[i] != 0)
                {
                    minvalue = nums[i];
                }
            }
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > 0)
                    nums[i] -= minvalue;
                if (nums[i] == 0 && !zeroIndex.count(i))
                {
                    zeroIndex.insert(i);
                }
            }
            operationNum++;
        }
        return operationNum;
    }
};