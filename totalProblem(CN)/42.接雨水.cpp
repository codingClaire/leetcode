/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
// 单调栈法： 81.27 % 36.13 %
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans =0;
        stack<int> stk;//单调栈
        int n = height.size();
        for(int i=0;i<n;i++)
        {
            //当前的height[i]比栈顶元素大
            while(!stk.empty() && height[i] > height[stk.top()])
            {
                // top 的下面一个元素是 left
                int top = stk.top();
                stk.pop();
                if(stk.empty())
                    break;
                int left = stk.top();
                int curWidth = i - left-1; //宽度很好理解
                // 高度：取height[left]和height[i]较小的，然后要减去height[top]
                //(这里相当于只用算一条，所以height[top]下面的部分可以忽略不计)
                int curHeight = min(height[left],height[i]) - height[top]; 
                ans +=curWidth*curHeight;
            }
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end
