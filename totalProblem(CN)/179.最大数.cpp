/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
// 二刷 91.27 %  75.61 %
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(),nums.end(),[](const int& x, const int& y){
            long sx=10,sy=10; //初始是long，而且要是10
            // 如果取1，过不去这个[0,9,8,7,6,5,4,3,2,1] 因为都是false，最大的变成0了
            // while有要取等
            while(sx<=y)
            {
                sx*=10;
            }
            while(sy<=x)
            {
                sy*=10;
            }
            return sx*x+y>sy*y+x;
        });
        if(nums[0]==0)
            return "0";
        string res="";
        for(int i=0;i<nums.size();i++)
        {
            res+=to_string(nums[i]);
        }
        return res;
    }
};
// @lc code=end

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