class Solution
{
public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        int lesnum = 0, targetnum = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < target)
                lesnum++;
            else if (nums[i] == target)
                targetnum++;
        }
        for (int i = lesnum; i < lesnum + targetnum; i++)
        {
            res.emplace_back(i);
        }
        return res;
    }
};