class Solution {
public:
    int reverse(int x)
    {
        long res = 0;
        vector<int> digits;
        long num = 10;
        while (x != 0)
        {
            digits.emplace_back(x % num / (num / 10));
            x = x - x % num;
            num *= 10;
        }
        num /= 10;
        for (int i = 0; i < digits.size(); i++)
        {
            num /= 10;
            res += digits[i] * num;
        }
        if (res > INT_MAX || res < INT_MIN)
            return 0;
        return res;
    }

    int countDistinctIntegers(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i=n-1;i>=0;i--)
        {
            nums.emplace_back(reverse(nums[i]));
        }
        unordered_set<int> st;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(!st.count(nums[i]))
            {
                ans++;
                st.insert(nums[i]);
            }
        }
        return ans;
    }
};