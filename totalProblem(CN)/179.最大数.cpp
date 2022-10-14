/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
// 90.95 % 76.83 %
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        //将两个数拼接后的结果，比大小，用这个函数来排序 x,y 要满足xy拼接比yx大
        sort(nums.begin(),nums.end(),[](const int &x,const int &y)
        {
            long sx=10,sy=10;
            while(sx<=x)
            {
                sx*=10;
            }
            while(sy<=y)
            {
                sy*=10;
            }
            return sy*x+y>sx*y+x;
        });
        // 第一个是0 后面的都不用看
        if(nums[0]==0)
            return "0";
        string ret;
        for(int &x: nums)
        {
            ret+=to_string(x);
        }
        return ret;
    }
};
// @lc code=end
