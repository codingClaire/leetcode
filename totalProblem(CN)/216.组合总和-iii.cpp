/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
// 组合枚举 100 %  6.71 %
class Solution
{
public:
    vector<int> temp;
    vector<vector<int>> ans;
    // 9个数选择k个数，让它们的和为n
    void DFS(int cur, int n,int k, int sum)
    {
        //当前选择的数 加上 剩余的个数也到不了k 
        //那么肯定全部加上也不够k个，直接剪枝
        if(temp.size()+(n-cur+1)<k || temp.size()>k)
            return;
        //保存条件： tmp存了k个数 并且加起来要等于n的情况
        if(temp.size() == k  && accumulate(temp.begin(),temp.end(),0) == sum)
        {
            ans.emplace_back(temp);
            return;
        }
        //每个数，选或不选
        temp.emplace_back(cur);
        DFS(cur+1, n,k,sum);
        temp.pop_back();
        DFS(cur+1, n,k,sum);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        DFS(1,9,k,n);
        return ans;
    }
};

// @lc code=end
// 自己写的回溯！ 25.28 % 95.61 %
class Solution
{
public:
    void backtrack(int k, int n, vector<int> &tmp, vector<vector<int>> &res)
    {
        if (k == 0 && n == 0)
        {
            res.emplace_back(tmp);
        }
        else if (k == 0 || n == 0)
        {
            return;
        }
        else
        {
            for (int i = 1; i <= 9; i++)
            {
                // 我自己的思路是，回溯阶段判断当前的i小于等于tmp已经存在的数
                // 这样就能避免两种重复
                bool flag = false;
                for (int j = 0; j < tmp.size(); j++)
                {
                    if (tmp[j] >= i)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag == true)
                    continue;
                tmp.emplace_back(i);
                backtrack(k - 1, n - i, tmp, res);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(k, n, tmp, res);
        return res;
    }
};