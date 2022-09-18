/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
// 树状数组  80.28 %  49.38 %
class Solution {
private:
    vector<int> a; // 无重复数组
    vector<int> c; // 前缀和数组
    void Discretization(vector<int> & nums)
    {
        // 使用unique之前要sort
        // unique函数返回的是unique后的新的结束位置
        // erase函数就将新的结束位置到原始结束位置的值都删除
        // 这样a就变成了一个无重复的数组
        a.assign(nums.begin(),nums.end());
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
    }
    void Init(int length)
    {   //初始化前缀和数组
        c.resize(length,0);
    }

    int getId(int x)
    {//根据值获取在去重数组中对应的id
        // TODO: 为什么要-a.begin()+1 ? 保证不存在的情况吗？
        return lower_bound(a.begin(),a.end(),x) -a.begin()+1;
    }
    int LowBit(int x)
    {
        return x&(-x);
    }

    int Query(int pos)
    {
        int ret=0;
        while(pos>0)
        {
            ret+=c[pos];
            pos-=LowBit(pos);
        }
        return ret;
    }

    void Update(int pos)
    {
        while(pos<c.size())
        {
            c[pos]+=1;
            pos+=LowBit(pos);
        }
    }

public:
    //动态维护前缀和，使用树状数组的思路
    vector<int> countSmaller(vector<int>& nums) 
    {
        vector<int> result;
        Discretization(nums);
        int len = nums.size();
        Init(len+5);
        for(int i=len-1;i>=0;i--)
        {   // 每次循环进行三个操作：
            // 1. 找id 2.根据id查询，并添加进结果数组 3. 更新id
            int id = getId(nums[i]);
            // 前一个就表示右侧有几个更小的元素
            result.emplace_back(Query(id-1));
            Update(id);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
// @lc code=end

