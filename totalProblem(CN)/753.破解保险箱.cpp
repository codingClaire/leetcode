/*
 * @lc app=leetcode.cn id=753 lang=cpp
 *
 * [753] 破解保险箱
 */

// @lc code=start
// 完全看不懂 我是真的看不懂
class Solution
{
private:
    unordered_set<int> seen;
    string ans;
    int highest; //即最后的位数，也是边的数量
    int k;

public:
    void dfs(int node)
    {
        for (int x = 0; x < k; x++)
        {
            int nei = node * 10 + x;
            if (!seen.count(nei))
            {
                //cout << nei << " " << nei % highest<<endl;
                seen.insert(nei);
                dfs(nei % highest);
                ans += (x + '0');
            }
        }
    }
    string crackSafe(int n, int k)
    {
        //n是密码位数 k是数字范围
        highest = pow(10, n - 1);
        this->k = k;
        dfs(0); //dfs的结果也是倒序的
        ans += string(n - 1, '0'); //末尾补上开始的n-1个0
        // 不需要reverse，TODO 
        return ans;
    }
};
// @lc code=end
