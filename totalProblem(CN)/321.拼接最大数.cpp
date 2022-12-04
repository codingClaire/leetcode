/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

// @lc code=start
// 单调栈解法 92.49 % 93.56 %
class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int m= nums1.size(), n =nums2.size();
        vector<int> maxSubseq(k,0); // 最后返回的结果
        int start = max(0,k-n); // nums1最少要取的个数， k-n如果是正数，就说明nums2全部取完也不够k, nums1最少要取k-n
        int end = min(k,m); //nums1最多要取的个数，全部取完
        for(int i=start;i<=end;i++)
        {// 逐个情况遍历
            vector<int> subseq1(getMaxSubseq(nums1,i));
            vector<int> subseq2(getMaxSubseq(nums2, k-i));
            // merge返回单调栈，赋值给curMaxSubseq，即从栈顶到栈底的元素
            vector<int> curMaxSubseq(merge(subseq1,subseq2));
            if(compare(curMaxSubseq,0,maxSubseq,0)>0)
                maxSubseq.swap(curMaxSubseq);
        }
        return maxSubseq; 
    }

    vector<int> getMaxSubseq(vector<int>& nums, int k)
    {   
        //从nums中取k个数的组成的最大子序列，用单调栈
        //从栈底到栈顶的元素单调递减
        //为什么要有remain? TODO
        int length = nums.size();
        vector<int> stack(k,0);
        int top = -1;
        //int remain = length-k; //找到k个数时，剩余的元素个数
        int remain = 0; // 可以剩下的元素，从零开始好像容易理解一些
        for(int i=0;i<length;i++)
        {
            //从左到右遍历nums
            int num = nums[i];
            // 当前栈内有元素，并且top的元素小于num，并且还有没有加入栈的元素
            // 就移除元素（这里移除元素只需要改变top的值就行，到时候更新的时候自然会覆盖）
            //while(top>=0 && stack[top]<num && remain>0)
            while(top>=0 && stack[top]<num && remain<length-k)
            {
                top--; // 舍弃当前的top
                //remain--; // 可以剩的元素减少了1
                remain++; // 移除当前top，即剩余的元素增加了1
            }
            if(top<k-1)
                stack[++top]=num; //将当前的数入栈
            else
                //remain--; // 可以剩的元素减一
                remain++;
        }
        return stack;
    }

    vector<int> merge(vector<int>& subseq1, vector<int>& subseq2)
    {
        //合并两个子序列，按照从大到小的顺序
        int x = subseq1.size(), y = subseq2.size();
        if(x == 0)
            return subseq2;
        if(y==0)
            return subseq1;
        int mergeLength = x+y;
        vector<int> merged(mergeLength);
        int idx1=0, idx2 = 0;
        for(int i=0;i<mergeLength;i++)
        {
            // compare为正的情况
            //1. 是subseq1当前的元素大于subseq2的
            //2. subseq1还有元素，但subseq2已经没有了
            //这两种情况都要加入subseq1[idx1]
            if(compare(subseq1,idx1,subseq2,idx2)>0)
                merged[i] = subseq1[idx1++];
            else
                merged[i] = subseq2[idx2++];
        }
        return merged;
    }

    int compare(vector<int>& subseq1, int index1, vector<int>& subseq2, int index2)
    {
        //这个比较还是比较优雅，值得学习
        int x= subseq1.size(), y = subseq2.size();
        while(index1<x && index2<y)
        {
            int difference = subseq1[index1] -subseq2[index2];
            //当前的元素不同，就直接返回difference
            if(difference!=0)
                return difference;
            index1++;
            index2++;
        }
        return (x-index1)-(y-index2);
    }
    
};
// @lc code=end
