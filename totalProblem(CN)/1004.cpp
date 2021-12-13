class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int res = 0;
        int start = 0, end = 0;
        int curk = 0;
        while (end < n)
        {
            if (nums[end] == 0)
                curk++;
            while (curk > k)
            {
                //注意这里要先判断然后再改变start的值
                if (nums[start] == 0)
                    curk--;
                start++;
            }
            res = fmax(res, end - start + 1);
            end++;
        }
        return res;
    }
};