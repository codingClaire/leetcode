/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            if (st.count(nums[i]) == 0)
            {
                st.insert(nums[i]);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
/*
//sort的版本
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i]==nums[i+1])
            {
                return true;
            }
        }
        return false;
    }
};
*/

/*
//用set的版本：时间空间都一般
//这里一个点：如果用unordered_map，时间上会快很多
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            if(st.count(nums[i])==0)
            {
                st.insert(nums[i]);
            }
            else
            {
                return true;
            }

        }
        return false;
    }
};
*/
