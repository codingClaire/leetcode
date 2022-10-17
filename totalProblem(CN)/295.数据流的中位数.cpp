/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
// 方法二：有序集合法
// 44.29 % 6.67%
class MedianFinder
{
public:
    multiset<int> nums;
    multiset<int>::iterator left, right;
    MedianFinder() : left(nums.end()), right(nums.end()) {}

    void addNum(int num)
    {
        const size_t n = nums.size();
        nums.insert(num);
        if (!n)
        { // n为0
            left = right = nums.begin();
        }
        else if (n & 1)
        { // n为奇数，left和right指向同一个中位数
            //这里的维护操作很简单
            if (num < *left)
                left--;
            else
                right++;
        }
        else
        { // n为偶数，left和right指向两个中位数
            if (num > *left && num < *right)
            { //插入left和right中间
                left++;
                right--;
            }
            else if (num >= *right)
            {//插入right右侧
                left++; // left和right此时到了一起
            }
            else
            { //插入left左侧（如果等于就是右侧，这时需要对left额外操作）
                right--;
                left = right;
            }
        }
    }

    double findMedian()
    {
        return (*left + *right) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
// 方法一：优先队列 7.55% 49.54%
// 用大小堆来维护中位数
class MedianFinder
{
public:
    priority_queue<int, vector<int>, less<int>> queMin;    // 大根堆
    priority_queue<int, vector<int>, greater<int>> queMax; // 小根堆
    // queMax只能和queMin相同或者相差一个
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (queMin.empty() || num <= queMin.top())
        { // 为空或者添加的数字比queMin的队头小

            queMin.push(num); //先放到queMin
            // queMax少了两个，要挪一个过去 这一步就是保证： Min只能比Max多一个
            if (queMax.size() + 1 < queMin.size())
            {
                queMax.push(queMin.top());
                queMin.pop();
            }
        }
        else
        {//添加的数字比queMin的队头大
            queMax.push(num); //先放
            // 等于的情况不需要考虑 这一步是要保证：Max和Min要相同
            if (queMax.size() > queMin.size())
            {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }

    double findMedian()
    {
        if (queMin.size() > queMax.size())
        {
            return queMin.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    }
};