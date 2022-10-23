/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
//  68.59 %  11.74 % 
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n), right(n);  
        stack<int> mono_stack;// 单调栈
        // 从左到右枚举高度，找到左侧比当前高度小的第一个index, 存入left中
        for(int i=0;i<n;i++)
        {
            while(!mono_stack.empty() && heights[mono_stack.top()]>=heights[i])
            {
                mono_stack.pop();
            }
            left[i] = mono_stack.empty()?-1:mono_stack.top();
            mono_stack.push(i);
        }
        // 找到右侧比当前高度小的第一个index, 存入right中
        mono_stack = stack<int>();
        for(int i=n-1;i>=0;i--)
        {
            while(!mono_stack.empty() && heights[mono_stack.top()]>=heights[i])
            {
                mono_stack.pop();
            }
            right[i] = mono_stack.empty()?n:mono_stack.top();
            mono_stack.push(i);
        }

        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans, (right[i]-left[i]-1)*heights[i]);
        }
        return ans;
    }

};
// @lc code=end


// 单调栈优化 52.52% 37.31%
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n,n);
        
        stack<int> mono_stack;
        for (int i = 0; i < n; i++) 
        {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) 
            {
                // 是一种反过来的思想，我也没完全搞明白
                right[mono_stack.top()] = i;
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};