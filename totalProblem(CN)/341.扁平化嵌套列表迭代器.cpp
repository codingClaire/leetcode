/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
//深度优先搜索方法：8.10% 80.22%
class NestedIterator
{
private:
    vector<int> vals;
    vector<int>::iterator cur;
    
    void DFS(const vector<NestedInteger> &nestedList)
    {
        for(auto &nest:nestedList)
        {
            if (nest.isInteger())
                vals.emplace_back(nest.getInteger());
            else    
                DFS(nest.getList());
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        DFS(nestedList);
        cur = vals.begin();
    }

    int next()
    {
        return *cur++;
    }

    bool hasNext()
    {
        return cur!=vals.end();
    }
};
// TODO：还有一种解法

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
