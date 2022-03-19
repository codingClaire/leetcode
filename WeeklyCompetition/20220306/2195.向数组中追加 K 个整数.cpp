class Solution
{
public:
    long long minimalKSum(vector<int> &nums, int k)
    {
        long long totalSum = 0;
        //增加两个元素：0和1e9+1
        nums.emplace_back(0); 
        nums.emplace_back(1e9 + 1);
        sort(nums.begin(), nums.end());
        long long curK = 0, pre_num = 0; 
        //curK是目前的追加数量，pre_num是遍历到num[i]的所有元素的和
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int interval_num = nums[i + 1] - 1 - nums[i]; //可添加的元素个数
            //周赛的时候没有考虑的细节问题，nums中的元素可能有重复
            if (nums[i + 1] != nums[i])
                pre_num += nums[i]; //累加之前的元素
            //无可添加元素或者下一个元素和当前元素相同的情况
            if (interval_num == 0 || nums[i + 1] == nums[i])
                continue;
            //满足添加k个整数的情况
            if (curK == k)
                break;
            curK += interval_num; //先追加
            if (curK >= k)
            {//当前元素大于k时，计算从num[i]到恰好k个需要添加的元素个数offset
                int offset = k - (curK - interval_num);
                // totalSum的计算是首项1，末项nums[i] + offset的求和，再减去pre_num
                // 需要使用static_cast<long long>进行隐式转换，否则会溢出
                totalSum = static_cast<long long>(nums[i] + offset + 1) * (nums[i] + offset) / 2 - pre_num;
                curK = k;//更新curK
            }
        }
        return totalSum;
    }
};

/* TLE解法： 这里的想法是顺着加的，这样会TLE，直到周赛时间不够的时候我才想到其实可以逆向思考
class Solution
{
public:
    long long minimalKSum(vector<int> &nums, int k)
    {
        long long totalSum = 0;
        nums.emplace_back(0);
        nums.emplace_back(int(2e9) + 1);
        sort(nums.begin(), nums.end());
        long long curK = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int interval_num = nums[i + 1] - 1 - nums[i];
            if (interval_num == 0 || nums[i + 1] == nums[i])
            continue;
            if (curK == k)
                break;
            curK += interval_num;
            if (curK <= k)
            {
                totalSum = totalSum + static_cast<long long>(nums[i] + nums[i + 1]) * (interval_num) / 2;
            }
            if (curK > k)
            {
                for (long long j = 0; j < k - (curK - interval_num); j++)
                {
                    totalSum = totalSum + nums[i] + 1 + j;
                }
                curK = k;
            }
        }
        return totalSum;
    }

};
*/

/*
TLE: [64,144,833,811,897]
63191253

*/