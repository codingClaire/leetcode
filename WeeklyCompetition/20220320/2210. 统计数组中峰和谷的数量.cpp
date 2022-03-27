class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        int res = 0;
        bool left_small_flag = false, left_big_flag = false;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            //正常的波峰
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            {
                res++;
                continue;
            }
            //正常的波谷
            if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1])
            {
                res++;
                continue;
            }
            //有平台的情况，可能是潜在的波峰，更新left_small_flag
            if (nums[i - 1] < nums[i] && nums[i + 1] == nums[i])
            {
                left_small_flag = true;
            }
            //有平台的情况，可能是潜在的波谷，更新left_big_flag
            if (nums[i - 1] > nums[i] && nums[i + 1] == nums[i])
            {
                left_big_flag = true;
            }
            //之前有潜在的波峰，判断是否能确定波峰
            if (left_small_flag == true)
            {
                if (nums[i] > nums[i + 1])
                {
                    left_small_flag = false;
                    res++;
                }
                else if (nums[i] < nums[i + 1])
                {
                    left_small_flag = false;
                }
            }
            //之前有潜在的波谷，判断是否能确定波谷
            if (left_big_flag == true)
            {
                if (nums[i] < nums[i + 1])
                {
                    res++;
                    left_big_flag = false;
                }
                if (nums[i] > nums[i + 1])
                {
                    left_big_flag = false;
                }
            }
        }
        return res;
    }
};