/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
//  100 %  13.5 %
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> q;
        for(auto &stone: stones)
        {
            q.push(stone);
        }
        while(q.size()>1)
        {
            int max1 = q.top();
            q.pop();
            int max2 = q.top();
            q.pop();
            int dele = min(max1, max2);
            if((max1-dele)!=0)
                q.push(max1-dele);
            if((max2-dele)!=0)
                q.push(max2-dele);
        }
        //cout<<q.size()<<endl;
        if(q.size() ==0)
            return 0;
        return q.top();
    }
};
// @lc code=end
