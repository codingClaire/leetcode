class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
                st.insert(nums[i]);
        }
        int maxv = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0 && st.count(-nums[i]))
                maxv = max(maxv,nums[i]);
        }
        return maxv;
    }
};