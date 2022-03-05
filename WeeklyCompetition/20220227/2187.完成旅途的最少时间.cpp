/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 *
 * [2187] 完成旅途的最少时间
 */

// @lc code=start
class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        sort(time.begin(), time.end());
        long long minTime = 0;
        long long maxTime = 1LL * totalTrips * time[0];
        // 最大的时间：用最快的车跑够指定次数
        //在[minTime,maxTime]区间中二分查找
        long long l = minTime, r = maxTime;
        while (l < r)
        {
            long long mid = (l + r) / 2;
            long curTrip = 0;
            //这里curTrip不能是int,否则无法通过最后一个测试用例
            //做的时候我以为这个不会超过int
            //但实际上大量的累加后很有可能超出int的范围
            for (int i = 0; i < time.size(); i++)
            {
                // for循环是更新curTrip的过程
                //它表示的是从0时刻到mid时刻能够跑的最多的旅程数
                //这个旅程数的求法就是让所有单程时间小于mid的车跑够mid时间
                if (time[i] > mid)
                {
                    break;
                }
                curTrip += mid / time[i];
            }
            if (curTrip < totalTrips)
            {//如果全部的车都跑满了还是不够旅程数，就说明要更大的时间
                l = mid + 1;
            }
            else
            {//如果旅程数超过了或者相等的情况，说明时间可能可以进一步压缩
                r = mid;
            }
        }
        //二分法不断寻找，直到l==r，这时返回l即可
        return l;
    }
};
// @lc code=end