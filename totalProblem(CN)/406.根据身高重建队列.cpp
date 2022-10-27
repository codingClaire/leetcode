/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
//方法二：从高到低遍历法 5.11 % 76.97 %
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &u, const vector<int> &v)
             { return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]); });
        //第i个人放入的时候，前面要恰好有k_i个人
        vector<vector<int>> ans;
        for(const vector<int>& person: people)
        {
            // 在k_i处，插入person
            ans.insert(ans.begin()+person[1],person);
        }
        return ans;
    }
};
// @lc code=end
// 方法一： 从低到高遍历法 80.81 % 92.02 %
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &u, const vector<int> &v)
             { return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]); });
        int n = people.size();
        vector<vector<int>> ans(n);
        // 按照从小到大的顺序开始遍历，相等的就是k大的先遍历
        for (const vector<int> &person : people)
        {
            // 从左往右的第k_i+1个空位置，坐下
            // 空位置只可能填入比当前的person更高的，或是等高但空位少的
            // 这样就可以满足题意了
            int space = person[1] + 1;
            for (int i = 0; i < n; i++)
            {
                if (ans[i].empty())
                {
                    space--;
                    if (!space)
                    {
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
        return ans;
    }