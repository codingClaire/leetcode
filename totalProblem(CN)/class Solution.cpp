// 100.00% 52.63%
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // 考虑被除数为最小值的情况
        if (dividend == INT_MIN)
        {
            if (divisor == 1)
            {
                return INT_MIN;
            }
            if (divisor == -1)
            {
                return INT_MAX;
            }
        }
        // 考虑除数为最小值的情况
        if (divisor == INT_MIN)
        {
            return dividend == INT_MIN ? 1 : 0;
        }
        // 考虑被除数为 0 的情况
        if (dividend == 0)
        {
            return 0;
        }

        // 一般情况，使用二分查找
        // 将所有的正数取相反数，这样就只需要考虑一种情况
        int rev = 1;
        if (dividend > 0)
        {
            dividend = -dividend;
            rev = -rev;
        }
        if (divisor > 0)
        {
            divisor = -divisor;
            rev = -rev;
        }

        // 快速乘
        auto quickAdd = [](int divisor, int mid, int dividend)
        {
            // x 和 y 是负数，z 是正数
            // 需要判断 z * y >= x 是否成立
            int result = 0, add = divisor;
            while (mid)
            {
                if (mid & 1)
                {
                    // 需要保证 result + add >= x
                    if (result < dividend - add)
                    {
                        return false;
                    }
                    result += add;
                }
                if (mid != 1)
                {
                    // 需要保证 add + add >= x
                    if (add < dividend - add)
                    {
                        return false;
                    }
                    add += add;
                }
                // 不能使用除法
                mid >>= 1;
            }
            return true;
        };

        int left = 1, right = INT_MAX, ans = 0;
        while (left <= right)
        {
            // 注意溢出，并且不能使用除法
            int mid = left + ((right - left) >> 1);
            bool check = quickAdd(divisor, mid, dividend);
            if (check)
            {
                ans = mid;
                // 注意溢出
                if (mid == INT_MAX)
                {
                    break;
                }
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return rev * ans;
    }
};